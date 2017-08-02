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
	struct sockaddr_in server_addr,
		               client_addr;



	SocketUtils_countArgs(argc, 3, "Usage: comp_two_server [valid ip_v4 address] [port]\n");


	SocketUtils_validateAddress( argv[2], &server_addr, 1025, 65535 );


	//SocketUtils_validatePort( argv[1], &port_no, 1, 1024 );


	//SocketUtils_createSocket(&sock_fd);
}
