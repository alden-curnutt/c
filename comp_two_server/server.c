/*
 * main.c
 *
 *  Created on: Jul 8, 2017
 *      Author: acurnutt
 */

#include "server.h"

int main(int argc, char **argv)
{
	long portNo = 0;
	int serverFd = 0,
		clientFd = 0,
		err = 0;

	socklen_t clientLen;
	struct sockaddr_in serverAddr = {0},
					   clientAddr = {0};
	char *buffer = NULL;
	char *banner = "You are being monitored. Like, right now..\n";

	SocketUtils_countArgs(argc, 2, "Usage: comp_two_server [port]\n");

	SocketUtils_validatePort( argv[1], &portNo, MIN_PORT, MAX_PORT );

	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(portNo);
	serverAddr.sin_addr.s_addr = INADDR_ANY;

	SocketUtils_createSocket(&serverFd);
	SocketUtils_bindSocket(serverFd, serverAddr);

	SocketUtils_listen(serverFd);

	printf("Listening for goodness on port: %ld\n", portNo);

	while (1)
	{
		clientLen = sizeof(clientAddr);

		SocketUtils_acceptConnection(&clientFd, serverFd, clientAddr, clientLen);

		if ( (send(clientFd, banner, strlen(banner), 0 )) == -1 )
		{
			perror("send");
			exit(EXIT_FAILURE);
		}

		while (1)
		{
			printf("---\nWaiting for message\n");

			SocketUtils_receiveUnknownData( &buffer, &clientFd );

			err = send(clientFd, buffer, strlen(buffer) + 1, 0 );
			if ( err == -1 )
			{
				perror("send");
				free(buffer);

				exit(EXIT_FAILURE);
			}
			else
			{
				printf("Message sent\n");
			}

			if ( strncmp(buffer, "quit\n", err) == 0 )
			{
				shutdown(clientFd, SHUT_RDWR);
				close(clientFd);
				free(buffer);

				exit(EXIT_SUCCESS);
			}

		}

	}

}















