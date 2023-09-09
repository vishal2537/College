#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <poll.h>
#include <sys/timerfd.h>
#define MAXMESSAGESIZE 3000

struct Frame
{
    int frame_no;
    char message[3000];
};

int can_send_frame, is_completed;
int server_fd, curr_socket;
unsigned char buffer[sizeof(struct Frame)];
int send_frame(struct Frame frame, int server_fd);
int receive_frame(struct Frame *frame, int server_fd);
int check_status_send_frame(FILE *file, int *frame_no, int *ch, struct Frame *frame);
void *client_request(void *arg);

int main(int argc, char const *argv[])
{
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("socket failed");
        return -1;
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = htonl(INADDR_ANY);
    uint16_t port = atoi(argv[1]);
    address.sin_port = htons(port);
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        perror("bind failed");
        return -1;
    }

    if (listen(server_fd, 3) < 0)
    {
        perror("listen");
        return -1;
    }

    if ((curr_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0)
    {
        perror("accept");
        return -1;
    }
    else
    {
        printf("CLIENT CONNECTED..\n");
    }

    int n = 0;
    can_send_frame = 1;

    pthread_t pthread;
    int *socket_no = malloc(sizeof(int)); // allocating the memory
    *socket_no = curr_socket;

    pthread_create(&pthread, NULL, &client_request, socket_no);
    while (1)
    {
        struct Frame frame;
        if (receive_frame(&frame, curr_socket) == -1)
        {
            perror("receive failed...");
            break;
        }
        else
        {
            if (is_completed)
            {
                break;
            }
            printf("ACK RECIEVED SENDING FRAME %d\n", (frame.frame_no) % 2);
        }

        n = 0;
        can_send_frame = 1;
    }
    printf("FILE TRANSFER IS COMPLETE\n");
    close(curr_socket);
    close(server_fd);
    exit(0);
}

int send_frame(struct Frame frame, int server_fd)
{
    memset(buffer, 0, sizeof(buffer));
    memcpy(buffer, &frame, sizeof(struct Frame));
    int bytesSent = send(server_fd, buffer, sizeof(struct Frame), 0);
    if (bytesSent == -1)
    {
        printf("Client disconnected...\n");
        return -1;
    }
    return 0;
}

int receive_frame(struct Frame *frame, int server_fd)
{
    memset(buffer, 0, sizeof(buffer));
    int bytesReceived = recv(server_fd, buffer, sizeof(struct Frame), 0); // receive the message into buffer array
    if (bytesReceived == -1)
    {
        printf("Client disconnected...\n");
        return -1;
    }
    memcpy(frame, buffer, sizeof(struct Frame)); // memorycopy into frame struct
    return 0;
}

int check_status_send_frame(FILE *file, int *frame_no, int *ch, struct Frame *frame)
{
    int n = 0;
    while (n < MAXMESSAGESIZE && ((*ch = getc(file)) != EOF))
    {
        (*frame).message[n++] = *ch;
    }

    (*frame).frame_no = *frame_no;

    if (*ch == EOF && n != MAXMESSAGESIZE)
    {
        (*frame).message[n++] = *ch;
    }
    if (send_frame((*frame), curr_socket) == -1)
    {
        perror("send failed...");
        fclose(file);
        return -1;
    }
    else
    {
        printf("\nS.NO. %d -- FRAME NUMBER : %d SENT\n", *frame_no, (*frame_no) % 2);
    }

    if (*ch == EOF)
    {
        return 2;
    }
    (*frame_no)++;

    can_send_frame = 0;
    return 0;
}

void *client_request(void *arg)
{
    int socket = *(int *)arg;
    FILE *file = fopen("input.txt", "r");
    int ch;
    int frame_no = 0;
    can_send_frame = 1;
    int timer_fd = timerfd_create(CLOCK_MONOTONIC, 0);
    if (timer_fd == -1)
    {
        perror("timerfd_create");
        fclose(file);
        pthread_exit(NULL);
    }

    struct itimerspec timer;
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_nsec = 0;
    timer.it_value.tv_sec = 2;
    timer.it_value.tv_nsec = 0;

    while (1)
    {
        struct Frame frame;
        uint64_t expirations;
        // Create a timer using timerfd_create
        if (timerfd_settime(timer_fd, 0, &timer, NULL) == -1)
        {
            perror("timerfd_settime");
            fclose(file);
            close(timer_fd);
            pthread_exit(NULL);
        }

        struct pollfd poll_fd;
        poll_fd.fd = timer_fd;
        poll_fd.events = POLLIN;

        if (can_send_frame)
        {
            int status = check_status_send_frame(file, &frame_no, &ch, &frame);
            if (status == 2 || status == -1)
                break;
        }
        // If the timer expires (poll returns 1), it prints a timeout message and
        // retransmits the last frame using send_frame. It also sets can_send_frame to 0 to
        // prevent sending additional frames until a response is received.
        while (1)
        {
            if (poll(&poll_fd, 1, 10) == 1)
            {

                printf("----TIMEOUT----\n");
                printf("RESENDING FRAME NUMBER %d\n", (frame.frame_no) % 2);
                send_frame(frame, socket);
                can_send_frame = 0;
                break;
            }
            else
            {
                if (can_send_frame == 1)
                    break;
            }
        }
    }

    is_completed = 1;
    fclose(file);
    pthread_exit(NULL); // exit running thread
}