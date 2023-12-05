#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <fcntl.h>

#define MAXLINE 200

// Function to retrieve command description
char *get_command_description(const char *command);

// Function to handle client connections
void client_request(int client_socket);

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
    pid_t childpid;

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1)    // Create a socket
    {
        perror("socket");
        exit(EXIT_FAILURE);
    }
    printf("[+] SERVER SOCKET IS CREATED.\n");
    int opt = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) == -1)    // Set socket options to reuse address
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    memset(&server_addr, '\0', sizeof(server_addr));  // Configure server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)   // Bind the socket to the specified port
    {
        perror("bind");
        exit(EXIT_FAILURE);
    }
    printf("[+] Bind to port %d\n", PORT);

    if (listen(server_fd, 10) == 0)   // Start listening for incoming connections
    {
        printf("[+] Listening....\n");
    }
    else
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    // Memory mapping for tracking the current client socket
    int *current_client_socket = mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANON, -1, 0);
    if (current_client_socket == MAP_FAILED)
    {
        perror("mmap");
        exit(EXIT_FAILURE);
    }
    *current_client_socket = -1;


    // int *current_client_socket = (int *)malloc(sizeof(int));
    // if (current_client_socket == NULL) {
    //     perror("malloc");
    //     exit(EXIT_FAILURE);
    // }
    // *current_client_socket = -1;

    childpid = fork();
    int valread ;
    char *busy_message = "Line busy, please try again later.\n";
    char recvline[MAXLINE]; // Buffer for received data

    // if(childpid == 0 )   // Child process handling client connections
    // {
    //     while (1)
    //     {
    //         addr_size = sizeof(client_addr);
    //         new_socket = accept(server_fd, (struct sockaddr *)&client_addr, &addr_size);
    //         if (*current_client_socket == -1)
    //         {
    //             *current_client_socket = new_socket;
    //             printf("%s\n", recvline);
    //             client_request(new_socket);
    //             *current_client_socket = -1; // Mark the current client as disconnected
    //         }
    //         else    // Server is busy, send "Line busy" message to the connecting client
    //         {
    //             printf("%s\n", recvline);
    //             send(new_socket, busy_message, strlen(busy_message), 0);
    //         }
    //         memset(recvline, 0, sizeof(recvline)); // Clear the buffer
    //         close(new_socket);    
    //     }        
    // }
    // else if (childpid > 0)   // Parent process accepting new client connections
    // {
        while (1)
        {
            addr_size = sizeof(client_addr);
            new_socket = accept(server_fd, (struct sockaddr *)&client_addr, &addr_size);  
            if (*current_client_socket == -1) 
            {
                *current_client_socket = new_socket;
                printf("%s\n", recvline);
                client_request(new_socket);
                *current_client_socket = -1; // Mark the current client as disconnected
            }
            else   // Server is busy, send "Line busy" message to the connecting client
            {
                printf("%s\n", recvline);
                send(new_socket, busy_message, strlen(busy_message), 0);
            }
            memset(recvline, 0, sizeof(recvline)); // Clear the buffer
            close(new_socket);    

        }
    // }
    // else{
    //     exit(EXIT_FAILURE);
    // }
    close(server_fd);
    return 0;
}

char *get_command_description(const char *command)
{
    char man_command[1024];
    printf("Received: %s\n", command);
    snprintf(man_command, sizeof(man_command), "man -f %s", command);
    FILE *file_pt = popen(man_command, "r");
    if (file_pt == NULL)
    {
        perror("popen error");
    }
    const int buffer_size = 1024;
    char buffer[buffer_size];
    char *temp;
    if (fgets(buffer, buffer_size, file_pt) != NULL)
    {
        temp = strdup(buffer);
    }
    else
    {
        temp = strdup("No such command found.\n");
    }
    pclose(file_pt);
    return temp;
}

void client_request(int client_socket)
{
    char recvline[MAXLINE];
    printf("Connected with client socket number %d\n", client_socket);
    while (1)
    {
        if (read(client_socket, recvline, MAXLINE) <= 0)   // Read data from the client
        {
            perror("read error");
            break;
        }
        printf("Client socket %d sent message: %s\n", client_socket, recvline);
        if (strcmp(recvline, "bye\n") == 0)
        {
            printf("Client requested to close the connection...\n");
            return;
        }
        char *description = get_command_description(recvline);
        write(client_socket, description, strlen(description));    // Send the command description back to the client
        free(description);      // Clean up memory and clear buffers
        memset(recvline, '\0', sizeof(recvline));
    }
    close(client_socket);         // Close the connection
}



// #include <netinet/in.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <sys/socket.h>
// #include <unistd.h>
// #include <sys/types.h>
// #include <sys/wait.h>
// #include <sys/mman.h>
// #include <fcntl.h>

// #define MAXLINE 200

// // Function to decode the received command
// int decode(char temp[], char recvline[], int curr_socket, size_t temp_size, size_t recvline_size);

// // Function to handle client requests
// int request(char recvline[], int curr_socket, char temp[], int valread, size_t temp_size, size_t recvline_size);

// int main(int argc, char const *argv[])
// {
//     pid_t pid;

//     int server_fd, new_socket, valread, curr_socket;
//     struct sockaddr_in address;
//     int addrlen = sizeof(address);

//     char *busy_message = "Line busy, please try again later.\n";
//     char *connectionstatus = "Connected to server...\n";

//     // Memory mapping for tracking the current client socket
//     int *current_client_socket = mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANON, -1, 0);
//     if (current_client_socket == MAP_FAILED)
//     {
//         perror("mmap");
//         exit(EXIT_FAILURE);
//     }
//     *current_client_socket = -1;

//     // Creating socket file descriptor
//     if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
//     {
//         perror("socket failed");
//         exit(EXIT_FAILURE);
//     }

//     address.sin_family = AF_INET;
//     address.sin_addr.s_addr = htonl(INADDR_ANY);
//     uint16_t port = atoi(argv[1]);
//     address.sin_port = htons(port);

//     // Forcefully attaching socket to the port
//     if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
//     {
//         perror("bind failed");
//         exit(EXIT_FAILURE);
//     }

//     if (listen(server_fd, 3) < 0)
//     {
//         perror("listen");
//         exit(EXIT_FAILURE);
//     }

//     pid = fork();

//     // Child process handling client connections
//     if (pid == 0)
//     {
//         while (1)
//         {
//             // Accept a new client connection
//             if ((curr_socket = accept(server_fd, (struct sockaddr *)&address,(socklen_t *)&addrlen)) < 0)
//             {
//                 perror("accept");
//                 exit(EXIT_FAILURE);
//             }

//             // Check if the server is already busy with another client
//             if (*current_client_socket == -1)
//             {
//                 // Mark the current client as connected
//                 *current_client_socket = curr_socket;  // Mark the current client as connected
//                 char temp[MAXLINE]; // Temp buffer for decoding
//                 char recvline[MAXLINE]; // Buffer for received data
//                 memset(recvline, 0, sizeof(recvline)); // Clear the buffer
//                 valread = read(curr_socket, recvline, sizeof(recvline));
//                 printf("%s\n", recvline);
//                 send(curr_socket, connectionstatus, strlen(connectionstatus), 0);
//                 request(recvline, curr_socket, temp, valread, sizeof(temp), sizeof(recvline));
//                 *current_client_socket = -1; // Mark the current client as disconnected
//             }
//             else
//             {
//                  // Server is busy, send "Line busy" message to the connecting client
//                 char temp[MAXLINE]; // Temp buffer for decoding
//                 char recvline[MAXLINE]; // Buffer for received data
//                 memset(recvline, 0, sizeof(recvline)); // Clear the buffer
//                 valread = read(curr_socket, recvline, sizeof(recvline));
//                 printf("%s\n", recvline);
//                 send(curr_socket, connectionstatus, strlen(connectionstatus), 0);
//                 valread = read(curr_socket, recvline, sizeof(recvline));
//                 send(curr_socket, busy_message, strlen(busy_message), 0);
//             }
//             close(curr_socket);
//         }
//     }

//     // Parent process accepting new client connections
//     else if (pid > 0)
//     {
//         while (1)
//         {
//             // Accept a new client connection
//             if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0)
//             {
//                 perror("accept");
//                 exit(EXIT_FAILURE);
//             }

//             // Check if the server is already busy with another client
//             if (*current_client_socket == -1)
//             {
//                 // Mark the current client as connected
//                 *current_client_socket = new_socket;
//                 char temp[MAXLINE]; // Temp buffer for decoding
//                 char recvline[MAXLINE]; // Buffer for received data
//                 memset(recvline, 0, sizeof(recvline)); // Clear the buffer
//                 valread = read(new_socket, recvline, sizeof(recvline));
//                 printf("%s\n", recvline);
//                 send(new_socket, connectionstatus, strlen(connectionstatus), 0);
//                 request(recvline, new_socket, temp, valread, sizeof(temp), sizeof(recvline));
//                 *current_client_socket = -1;
//             }
//             else
//             {
//                 // Server is busy, send "Line busy" message to the connecting client
//                 char temp[MAXLINE]; // Temp buffer for decoding
//                 char recvline[MAXLINE]; // Buffer for received data
//                 memset(recvline, 0, sizeof(recvline)); // Clear the buffer
//                 valread = read(new_socket, recvline, sizeof(recvline));
//                 printf("%s\n", recvline);
//                 send(new_socket, connectionstatus, strlen(connectionstatus), 0);
//                 valread = read(new_socket, recvline, sizeof(recvline));
//                 send(new_socket, busy_message, strlen(busy_message), 0);
//             }
//             close(new_socket);
//         }
//     }
//     else
//     {
//         printf("Server crashed...");
//         exit(EXIT_FAILURE);
//     }

//     // Close the listening socket
//     close(server_fd);

//     exit(0);
// }


// int decode(char temp[], char recvline[], int curr_socket, size_t temp_size, size_t recvline_size)
// {
//     memset(temp, 0, temp_size);
//     printf("Received: %s\n", recvline);
//     sprintf(temp, "man -f %s", recvline);

//     FILE *fp = popen(temp, "r");
//     if (fp == NULL)
//     {
//         perror("popen error");
//         return -1;
//     }
//     else
//     {
//         memset(recvline, 0, recvline_size); // Clear the buffer
//         fgets(recvline, recvline_size, fp);
//         if (pclose(fp) != 0)
//         {
//             strcpy(recvline, "no such command...\n");
//         }
//         send(curr_socket, recvline, strlen(recvline), 0);
//     }
//     return 0;
// }

// int request(char recvline[], int curr_socket, char temp[], int valread, size_t temp_size, size_t recvline_size)
// {
//     while (1)
//     {
//         memset(recvline, 0, recvline_size); // Clear the buffer
//         valread = read(curr_socket, recvline, recvline_size);
//         if (valread <= 0)
//         {
//             printf("Client disconnected...\n");
//             return -1;
//         }

//         if (strcmp(recvline, "bye\n") == 0)
//         {
//             printf("Client requested to close the connection...\n");
//             return -1;
//         }
//         int status = decode(temp, recvline, curr_socket, temp_size, recvline_size);
//         if (status == -1)
//         {
//             printf("error...");
//         }
//     }
// }
