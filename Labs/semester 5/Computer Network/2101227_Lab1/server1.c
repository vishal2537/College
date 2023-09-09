#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/mman.h>
// #include <sys/socket.h>
// #include <sys/types.h>
// #include <arpa/inet.h>
// #include <sys/wait.h>
// #include <fcntl.h>
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
    int *current_client = mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANON, -1, 0);
    if (current_client == MAP_FAILED)
    {
        perror("mmap");
        exit(EXIT_FAILURE);
    }
    *current_client = -1;
    char *busy_message = "Line busy, please try again later.\n";
    char recvline[MAXLINE]; // Buffer for received data
    childpid = fork();
    while (1)
    {
        addr_size = sizeof(client_addr);
        new_socket = accept(server_fd, (struct sockaddr *)&client_addr, &addr_size);  
        if (*current_client == -1) 
        {
            *current_client = new_socket;
            printf("%s\n", recvline);
            client_request(new_socket);
            *current_client = -1; // Mark the current client as disconnected
        }
        else   // Server is busy, send "Line busy" message to the connecting client
        {
            printf("%s\n", recvline);
            send(new_socket, busy_message, strlen(busy_message), 0);
        }
        memset(recvline, 0, sizeof(recvline)); // Clear the buffer
        close(new_socket);    
    }
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