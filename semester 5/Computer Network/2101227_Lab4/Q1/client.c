#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#define MAXMESSAGESIZE 3000

int client_fd;
struct Frame
{ // maintain a struct of message to send over network
    int frame_no;
    char message[3000];
};

unsigned char buffer[sizeof(struct Frame)];
int send_frame(struct Frame frame, int client_fd);
int receive_frame(struct Frame *frame, int client_fd);

int main(int argc, char const *argv[])
{
    struct sockaddr_in servaddr;
    if (argc != 3)
    {
        printf("Usage: %s <IP address> <Port>\n", argv[0]);
        return -1;
    }
    if ((client_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("socket error");
        return -1;
    }

    servaddr.sin_family = AF_INET;
    uint16_t port = atoi(argv[2]);
    servaddr.sin_port = htons(port);

    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0)
    {
        perror("inet_pton error");
        return -1;
    }

    if (connect(client_fd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    {
        perror("connection error");
        return -1;
    }
    else
    {
        printf("CONNECTION ESTABLISH..\n");
    }

    FILE *file = fopen("output.txt", "wb");
    int n = 0;
    while (1)
    {
        struct Frame frame;
        if (receive_frame(&frame, client_fd) == -1)
        {
            perror("connection closed...");
            return -1;
        }
        else
        {
            printf("\nS.NO. %d -- FRAME NUMBER : %d RECIEVED.\n", frame.frame_no, (frame.frame_no) % 2);
        }
        while ((n < MAXMESSAGESIZE) && (frame.message[n] != EOF))
        {
            putc(frame.message[n], file);
            n++;
        }
        if (frame.message[n] == EOF)
        {
            break;
        }
        frame.frame_no += 1;
        strcpy(frame.message, "\nFRAME RECIEVED..");

        if (send_frame(frame, client_fd) == -1)
        {
            perror("connection closed...");
            return -1;
        }
        else
        {
            printf("ACK %d SENT!\n", (frame.frame_no) % 2);
        }
        n = 0;
    }
    printf("FILE RECIEVED AND SAVED AS : 'output.txt'\n");
    close(client_fd);
    exit(0);
}

int send_frame(struct Frame frame, int client_fd)
{
    bzero(buffer, sizeof(buffer));
    memcpy(buffer, &frame, sizeof(struct Frame));
    int bytes_sent = send(client_fd, buffer, sizeof(struct Frame), 0);
    if (bytes_sent == -1)
    {
        printf("Client disconnected...\n");
        return -1;
    }
    return 0;
}

int receive_frame(struct Frame *frame, int client_fd)
{
    bzero(buffer, sizeof(buffer));
    int bytes_received = read(client_fd, buffer, sizeof(struct Frame)); // receive the message into buffer array
    if (bytes_received == -1)
    {
        printf("Client disconnected...\n");
        return -1;
    }
    memcpy(frame, buffer, sizeof(struct Frame)); // memorycopy into frame struct
    return 0;
}