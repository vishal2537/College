#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#define CHUNK_SIZE 5000

int main(int argc, char **argv) {

     if (argc != 2)
    {
        printf("USAGE: %s <PORT>\n", argv[0]);
        return 1;
    }

    int PORT = atoi(argv[1]);
    int serverSocket, clientSocket;
    struct sockaddr_in serverAddr, clientAddr;
    socklen_t clientAddrLen = sizeof(clientAddr);
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        perror("Server socket creation failed");
        return 1;
    }
    printf("[+]Server socket created successfully.\n");
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    if (bind(serverSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == -1) {
        perror("Bind failed");
        close(serverSocket);
        return 1;
    }
    printf("[+]Binding successfull.\n");
    if (listen(serverSocket, 1) == -1) {
        perror("Listen failed");    
        close(serverSocket);
        return 1;
    }
    clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddr, &clientAddrLen);
    if (clientSocket == -1) {
        perror("Accept failed");
        close(serverSocket);
        return 1;
    }

    FILE *outputFile = fopen("alice29_output.txt", "wb");
    if (outputFile == NULL) {
        perror("Failed to open output file");
        close(clientSocket);
        close(serverSocket);
        return 1;
    }
    char buffer[CHUNK_SIZE];
    ssize_t bytesRead;
    while ((bytesRead = recv(clientSocket, buffer, CHUNK_SIZE, 0)) > 0) {
        fwrite(buffer, 1, bytesRead, outputFile);
        send(clientSocket, "ACK", 3, 0);
    }
    fclose(outputFile);
    printf("[+]Data written in the file successfully.\n");
    close(clientSocket);
    close(serverSocket);
    return 0;
}