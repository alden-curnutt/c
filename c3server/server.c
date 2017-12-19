/*
 * server.c
 *
 *  Created on: Dec 4, 2017
 *      Author: acurnutt
 */

#include "server.h"

int main( int argc, char **argv )
{
	long port = 0;
	int serverFd = 0,
		clientFd = 0,
		optval = 1;
	socklen_t clientLen = 0;
	struct sockaddr_in serverInfo = {0},
			           clientInfo = {0};
	char *buffer = NULL;
	char *banner = "Super sweet banner";

	SocketUtils_countArgs( argc, 2, "Usage: server [port]\n" );

	SocketUtils_validatePort( argv[1], &port, MIN_PORT, MAX_PORT );

	serverInfo.sin_family = AF_INET;
	serverInfo.sin_port = htons(port);
	serverInfo.sin_addr.s_addr = INADDR_ANY;

	SocketUtils_createSocket( &serverFd );

	setsockopt(serverFd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof optval);

	return EXIT_SUCCESS;
}
