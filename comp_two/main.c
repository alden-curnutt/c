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
	int server_fd = 0, client_fd = 0, data_size = 0;
	socklen_t client_len;
	struct sockaddr_in serv_addr, client_addr;
	char buffer[BUFFER];

	SocketUtils_countArgs(argc);
	SocketUtils_checkPort( argv, &port_no );

	// filling serv_addr w / server info
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(port_no);
	serv_addr.sin_addr.s_addr = INADDR_ANY;

	SocketUtils_createSocket(&server_fd);
	printf("sock_fd is %d\n", server_fd);



	if ( (bind(server_fd, (struct sockaddr *) &serv_addr, sizeof(serv_addr))) < 0 )
	{
		/**
		 * validating bind to socket
		 */
		printf("Error binding to socket.\n");
		exit(1);
	}



	if ( (listen(server_fd, MAX_CONN)) < 0 )
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


		//printf("before accept\n");
		if ( (client_fd = accept(server_fd, (struct sockaddr *) &client_addr, &client_len)) < 0 )
		{
			/**
			 * validating accept of new connection
			 */
			printf("Error accepting new connection.\n");
			exit(1);
		}
		//printf("after accept\n");

		while (1)
		{


			if ( !(data_size = recv(client_fd, buffer, BUFFER, 0)) )
				break;

			if ( data_size < 0 )
			{
				printf("Error reading client data\n");
				exit(1);
			}


			printf("data size: %d\nbuffer   : %s\n", data_size, buffer);
		}


	}

}















