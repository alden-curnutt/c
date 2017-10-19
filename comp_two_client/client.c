/*
 * main.c
 *
 *  Created on: Jul 21, 2017
 *      Author: acurnutt
 */

#include "client.h"

int main( int argc, char **argv )
{
	//TODO - use camelCase for variable names | done
	int sockFd = 0,
		err = 0;
	long portNum = 0;
	//TODO - always init variabeles
	struct sockaddr_in serverAddr;

	char *buffer;
	size_t bufsize = 0,
	       messageLen = 0;
	//TODO - do not place large buffers on the stack, also do not hard code numbers for the size of buffers
	char recvline[1024];


	SocketUtils_countArgs(argc, 3, "Usage: comp_two_server [valid ip_v4 address] [port]\n");


	/**
	 * Validate ip address
	 */
	//TODO - check for exact return values that are error conditions | done
	if (inet_pton( AF_INET, argv[1], &(serverAddr.sin_addr) ) == -1)
	{
		perror("inet_pton");
		exit(EXIT_FAILURE);//TODO - macro
	}

	/**
	 * Validate port number
	 */
	SocketUtils_validatePort( argv[2], &portNum, MIN_PORT, MAX_PORT );//TODO - 65535 is MAX_PORT - define that as a macro, also do not allow reserved ports, MIN_PORT = 1024 | done
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(portNum);




	/**
	 * Create client socket
	 */
	SocketUtils_createSocket(&sockFd);


	//TODO - check for exact error value _ done
	if (connect(sockFd, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == -1 )
	{
		perror("connect");
		exit(EXIT_FAILURE);
	}
	printf("Successful connection to server\n\n");


	//TODO - do error checking on recv | done
	err = recv(sockFd, recvline, 1024, 0);
	if ( err == -1 )
	{
		perror("recv");
		exit(EXIT_FAILURE);
	}
	printf("%s\n", recvline);

	while (1)
	{
		/**
		 * User input
		 */
		buffer = NULL;
		bufsize = 0;

		printf("\n> ");

		//TODO - look at man page for getline, reset bufsize to 0, buffer needs to be freed after every round
		messageLen = getline( &buffer, &bufsize, stdin );

		//TODO - error checking
		send(sockFd , buffer , strlen(buffer) + 1 , 0 );

		memset(buffer, 0, sizeof(bufsize));

		//TODO - possible buffer overflow, recvline size = 1024, user can type larger message than that
		//easiest fix is to use the same buffer and zero the memory out before receiving
		err = recv(sockFd, buffer, bufsize, 0);
		//TODO - check for err = -1 or 0
		if ( err < 0 )
		{
			perror("recv failed\n");
		}
		else
		{
			printf("Echo:  %s\n", buffer);
		}


		//TODO - use strncmp | done
		if ( strncmp(buffer, "quit\n", messageLen) == 0 )
		{
			break;
		}


		memset(buffer, 0, sizeof(bufsize));
	}

	shutdown(sockFd, SHUT_RDWR);
	close(sockFd);
	//TODO - close | done
}










