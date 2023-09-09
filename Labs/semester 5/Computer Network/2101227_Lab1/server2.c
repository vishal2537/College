#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
// #include <sys/socket.h>
// #include <sys/types.h>
// #include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/wait.h>

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

    // Create a socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror("socket");
        exit(EXIT_FAILURE);
    }
    printf("[+] SERVER SOCKET IS CREATED.\n");
    int opt = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) == -1)
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    memset(&server_addr, '\0', sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("bind");
        exit(EXIT_FAILURE);
    }
    printf("[+] Bind to port %d\n", PORT);
    if (listen(server_fd, 10) == 0)
    {
        printf("[+] Listening....\n");
    }
    else
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    while (1)
    {
        addr_size = sizeof(client_addr);
        new_socket = accept(server_fd, (struct sockaddr *)&client_addr, &addr_size);
        if (new_socket < 0)
        {
            perror("accept");
            exit(EXIT_FAILURE);
        }
        printf("Connection accepted from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
        if ((childpid = fork()) == 0)
        {
            close(server_fd);
            client_request(new_socket);
            exit(0);
        }
        else
        {
            printf("New process %d\n", childpid);
            close(new_socket);
            while (waitpid(-1, NULL, WNOHANG) > 0);
        }
    }
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
        if (read(client_socket, recvline, MAXLINE) <= 0)
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
        write(client_socket, description, strlen(description));
        free(description);
        memset(recvline, '\0', sizeof(recvline));
    }
    close(client_socket);
}