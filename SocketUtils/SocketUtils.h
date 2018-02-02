/*
 * SocketUtils.h
 *
 *  Created on: Jul 18, 2017
 *      Author: acurnutt
 */

#ifndef SOCKETUTILS_H_
#define SOCKETUTILS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/socket.h>
#include <netinet/in.h>

#include <StdUtils.h>

#define PORT_LEN 4
#define MAX_CONN 10
#define BUFFER 10
#define NEWLINE '\n'

void SocketUtils_countArgs( int argc, int requiredCount, char msg[] );
void SocketUtils_validatePort( char *argv, long *port,  long min, long max );
void SocketUtils_createSocket( int *sock_fd );
void SocketUtils_bindSocket( int serverFd, struct sockaddr_in server_addr );
void SocketUtils_listen( int serverFd );
void SocketUtils_acceptConnection(int *clientFd, int serverFd, struct sockaddr_in client_addr, socklen_t client_len);
void SocketUtils_receiveUnknownData( char **buffer, int *clientFd );

#endif /* SOCKETUTILS_H_ */
