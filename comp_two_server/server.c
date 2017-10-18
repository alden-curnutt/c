/*
 * main.c
 *
 *  Created on: Jul 8, 2017
 *      Author: acurnutt
 */

#include "server.h"

int main(int argc, char **argv)
{
	//TODO - use camelCase for variable names | done
	long portNo = 0;
	int serverFd = 0,
		clientFd = 0,
		err = 0,
		dataSize = 0;
	//TODO - always init variables | done
	socklen_t clientLen;
	struct sockaddr_in serverAddr,
					   clientAddr;
	char* buffer = NULL;
	char *banner = "\n\n  ┌──────────────────────┐\n│  Comp 2 Echo Server  │\n├──────────────────────┤\n│   Echo some stuff!   │\n└──────────────────────┘\n";


	SocketUtils_countArgs(argc, 2, "Usage: comp_two_server [port]\n");
	SocketUtils_validatePort( argv[1], &portNo, MIN_PORT, MAX_PORT ); //TODO - 65535 is MAX_PORT - define that as a macro, also do not allow reserved ports, MIN_PORT = 1024 | done

	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(portNo);
	serverAddr.sin_addr.s_addr = INADDR_ANY;

	SocketUtils_createSocket(&serverFd);

	//TODO - put in utils, check for correct error return value, use perror when appropriate | done
	SocketUtils_bindSocket(serverFd, serverAddr);


	//TODO - put in utils, check for correct error return value, use perror when appropriate | done


	SocketUtils_listen(serverFd);
	printf("Listening for goodness on port: %ld\n", portNo);



	while (1)
	{
		int currentBufferSize = BUFFER;
		int i = 0;

		// main send / receive loop
		clientLen = sizeof(clientAddr);



		SocketUtils_acceptConnection(&clientFd, serverFd, clientAddr, clientLen);



		//TODO - check for error | done
		if ( (send(clientFd, banner, strlen(banner) + 1, 0 )) == -1 )
		{
			perror("send");
			exit(1);
		}


		while (1)
		{

			//TODO - free memory that was allocated before every exit or break from scope
			char* tempBuff = NULL;

			//TODO - error checking for calloc | done
			if ( (buffer = (char *)calloc(BUFFER, sizeof(char))) == NULL )
			{
				perror("calloc");
				exit(1);
			}


			i = 0;

			while ( 1 )
			{
				printf("---\nWaiting for chat\n");
				//TODO - read in one less than size of buffer to ensure that it has a null terminator
				dataSize = recv(clientFd, buffer+(BUFFER*i), BUFFER, 0);

				if ( dataSize == -1 )
				{
					perror("recv");
					exit(1);
				}
				else if ( !dataSize )
				{
					//TODO - perror does not make sense here | done
					break;
				}

				printf("message: %s\n", buffer);

				i++;

				if ( strchr(buffer, NEWLINE) )
				{
					break;
				}

				tempBuff = (char*)realloc(buffer, currentBufferSize += BUFFER);

				if(tempBuff != NULL) {
					buffer = tempBuff;
					tempBuff = NULL;
				}
				else
				{
					perror("Reallocation failed.\n");
					free(buffer);
					exit(EXIT_FAILURE);
				}
				//TODO - zero out the portion of buffer that was reallocated
			}



			err = send(clientFd, buffer, strlen(buffer) + 1, 0 );
			if ( err == -1 )
			{
				perror("send");
			}
			else
			{
				printf("Message sent\n");
			}


			//TODO - strcmp is not a safe function, use strncmp, break from loop, close clientFD as well
			//TODO - also break from the loop when recv returns 0
			if ( strncmp(buffer, "quit\n", err) == 0 )
				shutdown(clientFd, SHUT_RDWR);

		}

	}

}















