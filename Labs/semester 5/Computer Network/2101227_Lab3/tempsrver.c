#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <pthread.h>
// #include <sys/mman.h>

#define MAX_LINE 300
#define MAX_NUMBER_OF_CLIENT 5
void *client_request_handler(void *client_socket);
void add_client(int socketid);
void remove_client(int socketid);

int number_of_connected_client = 0;
int arr_client_socket[MAX_NUMBER_OF_CLIENT];
pthread_mutex_t socket_mutex ;

void set_arr_minus_one()
{
    for (int i = 0; i < MAX_NUMBER_OF_CLIENT; i++)
    {
        arr_client_socket[i] = -1;
    }
    
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("USAGE: %s <PORT>\n", argv[0]);
        return 1;
    }
    int PORT = atoi(argv[1]);
    int server_fd, new_socket, ret;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_size;
    pthread_t child_threads;
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) // Create a socket
    {
        perror("socket");
        exit(1);
    }
    printf("[+] SERVER SOCKET IS CREATED.\n");
    int t = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &t, sizeof(t)) == -1) // Set socket options to reuse address
    {
        exit(1);
    }
    memset(&server_addr, '\0', sizeof(server_addr)); // Configure server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) // Bind the socket to the specified port
    {
        perror("bind");
        exit(1);
    }
    printf("[+] Bind to port %d\n", PORT);

    if (listen(server_fd, 5) == 0) // Start listening for incoming connections
    {
        printf("[+] Listening....\n");
    }
    else
    {
        perror("listen");
        exit(1);
    }
    set_arr_minus_one();
    pthread_mutex_init(&socket_mutex, NULL);
    while (1)
    {
        addr_size = sizeof(client_addr);
        new_socket = accept(server_fd, (struct sockaddr *)&client_addr, &addr_size);
        if (new_socket < 0)
        {
            printf("error");
            exit(0);
        }
        if(number_of_connected_client < MAX_NUMBER_OF_CLIENT){
            printf("[+] CLIENT IS CONNECTED USING PORT NUMBER : %d\n", htons(client_addr.sin_port));
            printf("NEW SOCKET : %d\n", new_socket);
            // pthread_mutex_lock(&socket_mutex);
            add_client(new_socket);
            number_of_connected_client++;
            printf("NUMER OF CONNECTED CLIENT : %d\n", number_of_connected_client);
            // pthread_mutex_unlock(&socket_mutex);
            if (pthread_create(&child_threads, NULL, client_request_handler, &new_socket) != 0)
            {
                perror("failed to create thread");
            }
        }
        else{
            close(new_socket);
            printf("failed to create thread");
        }
    }
    // pthread_mutex_destroy(&socket_mutex);
    close(server_fd);
    return 0;
}

void add_client(int socketid)
{
    for(int i=0;i<MAX_NUMBER_OF_CLIENT;i++)
    {
        if(arr_client_socket[i] == -1)
        {
            arr_client_socket[i] = socketid;
            break;
        }
    }
    return;
}

void remove_client(int socketid)
{
    for(int i=0;i<MAX_NUMBER_OF_CLIENT;i++)
    {
        if(arr_client_socket[i] == socketid)
        {
            arr_client_socket[i] = -1;
            break;
        }
    }
    return;
}

void *client_request_handler(void *client_socket)
{
    int new_socket = *(int *)client_socket;
    while (1)
    {
        char recvline[MAX_LINE];
        char temprecvline[MAX_LINE];
        char destination_client_id[10];
        int sourceid;
        if(read(new_socket, recvline, sizeof(recvline))<=0){
            break;
        }
        strcpy(temprecvline, recvline);
        sscanf(temprecvline, "%d %s %[^\n]", &sourceid, destination_client_id, temprecvline);
        if (sourceid == -1)
        {
            break;
        }
        else
        {
            printf("MESSAGE : %s \n", recvline);
            // pthread_mutex_lock(&socket_mutex);
            for (int i = 0; i < number_of_connected_client; i++)
            {
                int client_sock = arr_client_socket[i];
                printf("client id : %d\n",arr_client_socket[i]);
                write(client_sock, recvline, strlen(recvline) + 1);
            }
            // pthread_mutex_unlock(&socket_mutex);
        }
        memset(recvline, '\0', sizeof(recvline));
        memset(temprecvline, '\0', sizeof(temprecvline));
        memset(destination_client_id, '\0', sizeof(destination_client_id));

    }
    // pthread_mutex_lock(&socket_mutex);
    remove_client(new_socket);
    number_of_connected_client--;
    // pthread_mutex_unlock(&socket_mutex);
    close(new_socket);
    printf("[+] CLIENT DISCONNECTED.\n");
    return NULL;
}