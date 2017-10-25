/*
 * SocketUtils.c
 *
 *  Created on: Jul 18, 2017
 *      Author: acurnutt
 */

#include "SocketUtils.h"


void SocketUtils_countArgs( int argc, int requiredCount, char msg[] )
{
	/**
	 * count arguments
	 */
	if ( argc != requiredCount )
	{
		printf("%s", msg);
		exit(EXIT_FAILURE);
	}
}


void SocketUtils_validatePort( char *argv, long *portNo, long min, long max )
{
	/**
	 * validating port in range
	 *     exits execution if port is not valid
	 */
	if ( (StdUtils_isInt(portNo, argv, PORT_LEN, min, max)) == 0 )
	{
		printf("[port]\n");
		exit(1);
	}
}



void SocketUtils_createSocket(int *sock_fd)
{
	/**
	 * validating open socket
	 */
	if ( (*sock_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1 )
	{
		perror("socket");
		exit(EXIT_FAILURE);
	}
}



void SocketUtils_bindSocket(int serverFd, struct sockaddr_in server_addr)
{
	/**
	 * Validate bind operation to socket
	 */
	if ( (bind(serverFd, (struct sockaddr *) &server_addr, sizeof(server_addr))) == -1 )
	{
		perror("bind");
		exit(EXIT_FAILURE);
	}
}



void SocketUtils_listen(int serverFd)
{
	/**
	 * Receives socket description and listens
	 */
	if ( (listen(serverFd, MAX_CONN)) < 0 )
	{
		perror("listen");
		exit(EXIT_FAILURE);
	}
}



void SocketUtils_acceptConnection(int *clientFd, int serverFd, struct sockaddr_in client_addr, socklen_t client_len)
{
	/**
	 * Accepts traffic from socket
	 */
	if ( (*clientFd = accept(serverFd, (struct sockaddr *) &client_addr, &client_len)) < 0 )
	{
		perror("accept");
		exit(EXIT_FAILURE);
	}
}



void SocketUtils_receiveUnknownData( char **buffer, int *clientFd )
{
	/**
	 * Receives data of unknown size from socket
	 */

	char *tempBuff = NULL;
	int i = 0,
	    dataSize = 0,
	    currentBufferSize = BUFFER,
	    increment = 0;

	if ( (*buffer = (char *)calloc(BUFFER, sizeof(char))) == NULL )
	{
		perror("calloc");
		exit(EXIT_FAILURE);
	}

	while ( 1 )
	{
		dataSize = recv(*clientFd, *buffer+(BUFFER*i), BUFFER, 0);

		if ( dataSize == 0 || dataSize == -1 )
		{
			free(buffer);
			buffer = NULL;
		}

		if ( dataSize == 0 )
		{
			printf("Closing connection\n");
			break;
		}
		else if ( dataSize == -1 )
		{
			perror("recv");
			exit(EXIT_FAILURE);
		}

		i++;

		if ( strchr(*buffer, NEWLINE) )
		{
			break;
		}

		tempBuff = (char*)realloc(*buffer, currentBufferSize += BUFFER);
		increment += BUFFER;

		memset( (buffer + increment) + 1, 0, BUFFER );

		if(tempBuff != NULL) {
			*buffer = tempBuff;
			tempBuff = NULL;
		}
		else
		{
			free(buffer);
			buffer = NULL;
			exit(EXIT_FAILURE);
		}
	}
}





