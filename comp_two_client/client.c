/*
 * main.c
 *
 *  Created on: Jul 21, 2017
 *      Author: acurnutt
 */

#include "client.h"

int main( int argc, char **argv )
{
	//TODO - use camelCase for variable names
	int sock_fd,
		err = 0;
	long port_no = 0; // end point for user's input
	//TODO - always init variabeles
	struct sockaddr_in server_addr;

	char *buffer;
	size_t bufsize = 0;
	size_t message;
	//TODO - do not place large buffers on the stack, also do not hard code numbers for the size of buffers
	char recvline[1024];


	SocketUtils_countArgs(argc, 3, "Usage: comp_two_server [valid ip_v4 address] [port]\n");


	/**
	 * Validate ip address
	 */
	//TODO - check for exact return values that are error conditions
	if (inet_pton( AF_INET, argv[1], &(server_addr.sin_addr) ) <= 0)
	{
		printf("error converting addy\n");
		exit(1);//TODO - macro
	}

	/**
	 * Validate port number
	 */
	SocketUtils_validatePort( argv[2], &port_no, 1, 65535 );//TODO - 65535 is MAX_PORT - define that as a macro, also do not allow reserved ports, MIN_PORT = 1024
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(port_no);




	/**
	 * Create client socket
	 */
	SocketUtils_createSocket(&sock_fd);


	//TODO - check for exact error value
	if (connect(sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0 )
	{
		perror("connection failed");
		exit(1);
	}
	printf("Successful connection to server\n\n");

	//TODO - do error checking on recv
	err = recv(sock_fd, recvline, 1024, 0);

	while (1)
	{
		/**
		 * User input
		 */
		printf("\n> ");

		buffer = NULL;
		//TODO - look at man page for getline, reset bufsize to 0, buffer needs to be freed after every round
		message = getline( &buffer, &bufsize, stdin );

		//TODO - error checking
		send(sock_fd , buffer , strlen(buffer) + 1 , 0 );

		//TODO - possible buffer overflow, recvline size = 1024, user can type larger message than that
		//easiest fix is to use the same buffer and zero the memory out before receiving
		err = recv(sock_fd, recvline, bufsize, 0);
		//TODO - check for err = -1 or 0
		if ( err < 0 )
			perror("recv failed\n");
		else
			printf("Echo:  %s\n", recvline);


		//TODO - use strncmp
		if ( strcmp(buffer, "quit\n") == 0 )
			break;


		memset(recvline, 0, sizeof(recvline));
	}

	shutdown(sock_fd, SHUT_RDWR);
	//TODO - close
}










