#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

void read_messages(int clientSocket, const char *curr_client_id) {
    char message[256];
    while (1) {
        if (read(clientSocket, message, sizeof(message)) <= 0) {
            perror("read error");
            break;
        }
        char destination_client_id[10];
        int source_client_id;

        if (sscanf(message, "%d %s %[^\n]",&source_client_id, destination_client_id, message) == 3) {
            if (strcmp(destination_client_id, curr_client_id) == 0) {
                printf("Message accepted by node {%s} from node {%d}..\n",destination_client_id,source_client_id);
                printf("Message : %s\n",message);
            } else {
                printf("Message from node {%d} is discard  by node {%s}. \n",source_client_id,curr_client_id);
            }
        }
		memset(message, '\0', sizeof(message));
		memset(destination_client_id, '\0', sizeof(destination_client_id));

    }
    close(clientSocket);
    exit(0);
}

void send_messages(int clientSocket, const char *curr_client_id) {
    char destination_client_id[10];
    char source_client_id[10];

    char message[256];
    while (1) {
        printf("enter {source id} {destination client ID} {message}: \n");
        scanf("%s", source_client_id);
        scanf("%s", destination_client_id);
        scanf(" %[^\n]s", message);
        if(atoi(curr_client_id) != atoi(source_client_id) && atoi(source_client_id) != -1)
        {
            continue;
        }
        char combinedMessage[300];
        snprintf(combinedMessage, sizeof(combinedMessage), "%s %s %s", source_client_id, destination_client_id, message);
        printf("Sent: %s\n", combinedMessage);
        write(clientSocket, combinedMessage, strlen(combinedMessage));
        memset(message, '\0', sizeof(message));
        memset(destination_client_id, '\0', sizeof(destination_client_id));
        memset(source_client_id, '\0', sizeof(source_client_id));
        memset(combinedMessage, '\0', sizeof(combinedMessage));
    }
    close(clientSocket);
    exit(0);
}

int main(int argc, char **argv) {
    if (argc != 4) {
        printf("Usage: %s <IP> <port> <curr_client_id>\n", argv[0]);
        return 1;
    }

    int clientSocket;
    struct sockaddr_in serverAddr;

    // Create socket
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket < 0) {
        perror("Error opening socket");
        exit(EXIT_FAILURE);
    }

    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = inet_addr(argv[1]);
    serverAddr.sin_port = htons(atoi(argv[2]));

    // Connect to server
    if (connect(clientSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    char curr_client_id[10];
    strcpy(curr_client_id, argv[3]);

    // Fork a child process for reading messages
    pid_t pid = fork();
    if (pid < 0) {
        perror("Fork failed");
    } else if (pid == 0) {
        // child process: Send messages
        send_messages(clientSocket,curr_client_id);
    } else {
        // parent process: Read and print messages
        read_messages(clientSocket, curr_client_id);
    }
    return 0;
}