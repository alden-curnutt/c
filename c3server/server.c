/*
 * server.c
 *
 *  Created on: Dec 4, 2017
 *      Author: acurnutt
 */

#include "server.h"


struct node
{
	int fd;

	TAILQ_ENTRY(node) nodes;
};


struct chatVars {
	int numClients;
	int clientFd;
} chatVars;


int main( int argc, char **argv )
{
	long port = 0;
	int serverFd = 0,
		optval = 1;
	socklen_t clientLen = 0;
	struct sockaddr_in serverInfo = {0},
			           clientInfo = {0};
	char *buffer = NULL;
	char *banner = "Super sweet banner";

	SocketUtils_countArgs( argc, 2, "Usage: server [port]\n" );

	SocketUtils_validatePort( argv[1], &port, MIN_PORT, MAX_PORT );

	SocketUtils_setNetOpts( &serverInfo, port);

	SocketUtils_createSocket( &serverFd );

	setsockopt(serverFd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof optval);

	SocketUtils_listen(serverFd);

	printf("werks\n");

	startChat(serverFd)
	{
		TAILQ_HEAD(head_s, node) head;
		TAILQ_INIT(&head);



	}


	return EXIT_SUCCESS;
}










