/*
 * main.c
 *
 *  Created on: Jul 8, 2017
 *      Author: acurnutt
 */

#include "server.h"

int main(int argc, char **argv)
{
	long port_no = 0; // end point for user's input
	int server_fd = 0,
	    client_fd = 0,
		data_size = 0;
	socklen_t client_len;
	struct sockaddr_in server_addr,
	                   client_addr;
	char* buffer = {0};

	SocketUtils_countArgs(argc, 2, "Usage: comp_two_server [port]\n");
	SocketUtils_validatePort( argv[1], &port_no, 1, 1024 );

	// filling serv_addr w / server info
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(port_no);
	server_addr.sin_addr.s_addr = INADDR_ANY;

	SocketUtils_createSocket(&server_fd);



	if ( (bind(server_fd, (struct sockaddr *) &server_addr, sizeof(server_addr))) < 0 )
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
		buffer = (char *)calloc(BUFFER, sizeof(char));
		int currentBufferSize = BUFFER;
		int i = 0;


		if ( (client_fd = accept(server_fd, (struct sockaddr *) &client_addr, &client_len)) < 0 )
		{
			/**
			 * validating accept of new connection
			 */
			printf("Error accepting new connection.\n");
			exit(1);
		}



		while (1)
		{
			char* tempBuff = NULL;

			while ( 1 )
			{
				data_size = recv(client_fd, buffer+(BUFFER*i), BUFFER, 0);

				if ( data_size <= 0 )
				{
					perror("Error reading client data\n");
					exit(1);
				}

				if ( !data_size )
				{
					perror("Done reading\n");
					break;
				}

				i++;
				tempBuff = (char*)realloc(buffer, currentBufferSize += BUFFER);

				if(tempBuff != NULL){
					buffer = tempBuff;
					tempBuff = NULL;
					free(tempBuff);
				}
				else
					perror("Reallocation failed.\n");

				if ( strchr(buffer, NEWLINE) )
					break;
			}

			printf("after loop: %s\n", buffer);

			break;

		}

	}

}















