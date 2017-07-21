/*
 * main.c
 *
 *  Created on: Jul 8, 2017
 *      Author: acurnutt
 */

#include "main.h"

int main(int argc, char **argv)
{
	long port_no = 0; // end point for user's input
	int sock_fd = 0, new_sock_fd = 0;
	socklen_t client_len;
	struct sockaddr_in serv_addr, client_addr;


	SocketUtils_countArgs(argc);
	SocketUtils_checkPort( argv, &port_no );

	// filling serv_addr w / server info
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(port_no);
	serv_addr.sin_addr.s_addr = INADDR_ANY;

	SocketUtils_createSocket(&sock_fd);
	printf("sock_fd is %d\n", sock_fd);



	if ( (bind(sock_fd, (struct sockaddr *) &serv_addr, sizeof(serv_addr))) < 0 )
	{
		/**
		 * validating bind to socket
		 */
		printf("Error binding to socket.\n");
		exit(1);
	}



	if ( (listen(sock_fd, MAX_CONN)) < 0 )
	{
		/**
		 * validating listen process
		 */
		printf("Error listening on socket.\n");
		exit(1);
	}
	printf("Listening for goodness on port: %ld\n", port_no);



	while (1)
	{
		// main send / receive loop
		client_len = sizeof(client_addr);

		if ( (new_sock_fd = accept(sock_fd, (struct sockaddr *) &client_addr, &client_len)) < 0 )
		{
			/**
			 * validating accept of new connection
			 */
			printf("Error accepting new connection.\n");
			exit(1);
		}

	}

}















