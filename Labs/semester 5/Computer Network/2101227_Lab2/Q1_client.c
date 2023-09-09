#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#define SIZE 5000

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("no IP address supplied");
		return 1;
	}
	
	int clientSocket;
	struct sockaddr_in serverAddr;   
	clientSocket = socket(AF_INET, SOCK_STREAM, 0);              
	if (clientSocket == -1)
	{
		perror("Client socket creation failed");
		return 1;
	}
	printf("[+]Server socket created successfully.\n");

	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(atoi(argv[1]));
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	if (connect(clientSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == -1)
	{
		perror("Connection to server failed");
		close(clientSocket);
		return 1;
	}
	printf("[+]Connected to Server.\n");
	FILE *inputFile = fopen("alice29.txt", "rb");
	if (inputFile == NULL)
	{
		perror("Failed to open input file");
		close(clientSocket);
		return 1;
	}
	int count = 0;
	char buffer[SIZE];
	size_t bytesRead;
	while ((bytesRead = fread(buffer, 1, SIZE, inputFile)) > 0)
	{
		if (send(clientSocket, buffer, bytesRead, 0) == -1)
		{
			perror("Send failed");
			break;
		}
		char ack[3];
		if (recv(clientSocket, ack, 3, 0) != 3 || strncmp(ack, "ACK", 3) != 0)
		{
			printf("Failed to receive ACK from server\n");
			break;
		}
		count++;
		printf("Received ACK from server: %.*s\n", 3, ack);
		printf("Byte recieved : %lu\n",bytesRead);
	}
	printf("[+]File data sent successfully.\n");
	// printf("NUMBER OF TIMES 'ACK' RECIEVED : %d\n",count);
	fclose(inputFile);

	printf("[+]Closing the connection.\n");
	close(clientSocket);
	return 0;
}