/*
 * main.c
 *
 *  Created on: Jul 21, 2017
 *      Author: acurnutt
 */

#include "client.h"

int main( int argc, char **argv )
{
	int serverFd = 0,
		err = 0;
	long portNum = 0;
	struct sockaddr_in serverAddr = {0};

	char *buffer = NULL,
		 *banner = NULL;
	size_t bufSize = 0,
	       messageLen = 0;

	SocketUtils_countArgs(argc, 3, "Usage: comp_two_server [valid ip_v4 address] [port]\n");

	//TODO - check for both error conditions separately
	err = inet_pton( AF_INET, argv[1], &(serverAddr.sin_addr) );
	if ( err == 0 )
	{
		printf("Invalid IP Address\n");
		exit(EXIT_FAILURE);
	}
	else if ( err == -1 )
	{
		perror("inet_pton");
		exit(EXIT_FAILURE);
	}


	SocketUtils_validatePort( argv[2], &portNum, MIN_PORT, MAX_PORT );
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(portNum);

	SocketUtils_createSocket(&serverFd);

	if (connect(serverFd, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == -1 )
	{
		perror("connect");
		exit(EXIT_FAILURE);
	}
	printf("Successful connection to server\n");
	printf("Enter " COLOR_GREEN "quit" COLOR_RESET " to stop the program\n\n");

	SocketUtils_receiveUnknownData( &banner, &serverFd );
	printf("%s\n", banner);

	while (1)
	{
		buffer = NULL;
		bufSize = 0;

		printf("\n> ");

		messageLen = getline( &buffer, &bufSize, stdin );

		if ( send(serverFd , buffer , strlen(buffer) + 1 , 0 ) == -1 )
		{
			perror("send");
			exit(EXIT_FAILURE);
		}

		memset(buffer, 0, sizeof(bufSize));

		//TODO - check for err = -1 or 0 separately (0 bytes recv'd means other side closed connection and is a valid state)
		err = recv(serverFd, buffer, bufSize, 0);

		if ( err == 0 )
		{
			printf("Closing connection\n");
			break;
		}
		else if ( err == -1 )
		{
			perror("recv"); /// TODO -- memory leak
			exit(EXIT_FAILURE);
		}
		else
		{
			printf("Echo:  %s\n", buffer);
		}

		if ( strncmp(buffer, "quit\n", messageLen) == 0 )
		{
			break;
		}
		memset(buffer, 0, sizeof(bufSize));
		free(buffer);
		buffer = NULL;
	}

	shutdown(serverFd, SHUT_RDWR);
	close(serverFd);
}










