#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_COMMAND_LENGTH 100

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[MAX_COMMAND_LENGTH] = {0};
    char output_buffer[1024];

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }

    // while(1){

        // Receive input command from the user
        printf("Enter a command (ls, cd, cat): ");
        fgets(buffer, MAX_COMMAND_LENGTH, stdin);

        // Send the command to the server
        send(sock, buffer, strlen(buffer), 0);

        // Receive and print the output from the server
        while (1) {
            int valread = read(sock, output_buffer, sizeof(output_buffer));
            if (valread <= 0) {
                break;
            }
            printf("%s", output_buffer);
        }

        // int i = strncmp("BYE",buffer,3);
        // if(i==0)
        // {
        //     break;
        // }

    // }

    // Close the socket
    close(sock);

    return 0;
}
