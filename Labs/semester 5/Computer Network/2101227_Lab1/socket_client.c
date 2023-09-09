#include <stdio.h>
#include <string.h> //strlen
#include <stdlib.h> //strlen
#include <sys/socket.h>
#include <arpa/inet.h> //inet_addr
#include <unistd.h>	   //write
#include <sys/types.h>

#define MAXLINE 200

int main(int argc, char **argv)
{

	int sockfd, n;
	char recvline[MAXLINE + 1];
	char sendline[MAXLINE + 1];
	struct sockaddr_in servaddr;
	if (argc != 3)
	{
		printf("no IP address supplied");	
		return 1;
	}

	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		printf("socket error");
		return 1;
	}
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(atoi(argv[2])); /* daytime server */

	// Convert IPv4 and IPv6 addresses from text to binary form
	int x;
	x = inet_pton(AF_INET, argv[1], &servaddr.sin_addr);
	if (x < 0)
	{
		printf("inet_pton error for %s", argv[1]);
		return 1;
	}

	if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
	{
		printf("connection errorr");
		return 1;
	}
	printf("Connected to server...\n");
	while (1)
	{
		printf("Please enter the message to the server: ");
		fgets(sendline, MAXLINE, stdin);
		sendline[strlen(sendline) - 1] = '\0'; // Remove the newline character

		int i = strncmp("bye",sendline,3);
        if(i==0)
        {
            break;
        }
		write(sockfd, sendline, strlen(sendline));
		if (read(sockfd, recvline, MAXLINE) <= 0)
		{
			perror("read error");
			break;
		}
		printf("Server reply: %s\n", recvline);
		memset(recvline, '\0', sizeof(recvline));
		memset(sendline, '\0', sizeof(sendline));
	}
	close(sockfd);
	exit(0);
}	