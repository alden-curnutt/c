/*
 * main.c
 *
 *  Created on: Jul 21, 2017
 *      Author: acurnutt
 */

#include "client.h"

int main( int argc, char **argv )
{
	int sock_fd;
	long port_no = 0; // end point for user's input
	struct sockaddr_in server_addr;

	char *buffer;
	size_t bufsize = 0;
	size_t message;


	SocketUtils_countArgs(argc, 3, "Usage: comp_two_server [valid ip_v4 address] [port]\n");


	/**
	 * Validate ip address
	 */
	if (inet_pton( AF_INET, argv[1], &(server_addr.sin_addr) ) <= 0)
	{
		printf("error converting addy\n");
		exit(1);
	}

	/**
	 * Validate port number
	 */
	SocketUtils_validatePort( argv[2], &port_no, 1, 1024 );
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(port_no);




	/**
	 * Create client socket
	 */
	SocketUtils_createSocket(&sock_fd);


	if (connect(sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0 )
	{
		perror("connection failed");

	}


	printf("Successful connection to server\n\n");

	while (1)
	{
		printf("starting while loop\n");
		/**
		 * User input
		 */
		printf("\n> ");

		buffer = NULL;

		printf("before getline\n");
		message = getline( &buffer, &bufsize, stdin );
		printf("after getline\n");
		//printf("%s\n", buffer);
		//printf("size of message was %zu\n", message);


		printf("before send\n");
		send(sock_fd , buffer , strlen(buffer) , 0 );
		printf("after send\n");

		printf("before read\n");
		read( sock_fd , buffer, 1024);
		printf("after read\n");
		printf("%s\n", buffer);

		printf("ending while loop\n");
	}
}










