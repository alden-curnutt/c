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
	char* buffer = {0};

	SocketUtils_countArgs(argc);
	SocketUtils_checkPort( argv, &port_no );

	// filling serv_addr w / server info
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(port_no);
	serv_addr.sin_addr.s_addr = INADDR_ANY;

	SocketUtils_createSocket(&server_fd);



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





		buffer = (char *)calloc(BUFFER, sizeof(char));

		int currentBufferSize = BUFFER;
		int i = 0;
		while (1)
		{
			char* tempBuff = NULL;
			printf("inside first while loop\n");

			while ( (data_size = recv(client_fd, buffer+(BUFFER*i), BUFFER, 0)) > 0 )
			{
				printf("starting while loop\n");

				if ( data_size < 0 )
				{
					printf("Error reading client data\n");
					exit(1);
				}

				if ( data_size == 0 )
					break;


				printf("data size: %d\nbuffer   : %s\n", data_size, buffer);


				printf("currentBufferSize %d\n", currentBufferSize);
				i++;
				tempBuff = (char*)realloc(buffer, currentBufferSize += BUFFER);

				if(tempBuff != NULL){
					buffer = tempBuff;
					tempBuff = NULL;
					free(tempBuff);
				}
				else{
					perror("Reallocation failed.\n");
				}

				printf("ending while loop\n");

				if ( data_size < BUFFER )
					break;
			}

			printf("after loop buffer is %s\n\n", buffer);

//			for ( int i = 0; i < buffer; i++ )
//			{
//				printf("%c", buffer[i]);
//			}
			break;

		}

	}

}















