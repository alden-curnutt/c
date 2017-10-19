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
	int serverFd = 0,
		err = 0;
	long portNum = 0;
	//TODO - always init variables | done
	struct sockaddr_in serverAddr = {0};

	char *buffer = NULL,
		 *banner = NULL;
	size_t bufSize = 0,
	       messageLen = 0;
	//TODO - do not place large buffers on the stack, also do not hard code numbers for the size of buffers | done

	SocketUtils_countArgs(argc, 3, "Usage: comp_two_server [valid ip_v4 address] [port]\n");

	//TODO - check for both error conditions
	if (inet_pton( AF_INET, argv[1], &(serverAddr.sin_addr) ) == -1)
	{
		perror("inet_pton");
		exit(EXIT_FAILURE); //TODO - macro | done
	}

	SocketUtils_validatePort( argv[2], &portNum, MIN_PORT, MAX_PORT );//TODO - 65535 is MAX_PORT - define that as a macro, also do not allow reserved ports, MIN_PORT = 1024 | done
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(portNum);

	SocketUtils_createSocket(&serverFd);

	//TODO - check for exact error value _ done
	if (connect(serverFd, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == -1 )
	{
		perror("connect");
		exit(EXIT_FAILURE);
	}
	printf("Successful connection to server\n\n");

	//TODO - do error checking on recv | done
	SocketUtils_receiveUnknownData( &banner, &serverFd );
	printf("%s\n", banner);

	while (1)
	{
		buffer = NULL;
		bufSize = 0;

		printf("\n> ");

		//TODO - look at man page for getline, reset bufsize to 0, buffer needs to be freed after every round | done
		messageLen = getline( &buffer, &bufSize, stdin );

		//TODO - error checking
		send(serverFd , buffer , strlen(buffer) + 1 , 0 );

		memset(buffer, 0, sizeof(bufSize));

		//TODO - possible buffer overflow, banner size = 1024, user can type larger message than that | done
		//easiest fix is to use the same buffer and zero the memory out before receiving
		err = recv(serverFd, buffer, bufSize, 0);
		//TODO - check for err = -1 or 0
		if ( err < 0 )
		{
			perror("recv");
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
		memset(buffer, 0, sizeof(bufSize));
		/// TODO -- free buffer here to avoid leak
	}

	shutdown(serverFd, SHUT_RDWR);
	close(serverFd);
	//TODO - close | done
}










