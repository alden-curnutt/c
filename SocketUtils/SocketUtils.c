/*
 * SocketUtils.c
 *
 *  Created on: Jul 18, 2017
 *      Author: acurnutt
 */

#include "SocketUtils.h"


void SocketUtils_countArgs( int argc )
{
	/**
	 * testing argument count
	 */
	if ( argc != 2 )
	{
		printf("Usage: comp_two [port]\n");
		exit(1);
	}
}


void SocketUtils_checkPort( char **argv, long *port_no )
{
	/**
	 * validating port in range
	 */
	if ( (*port_no = StdUtils_isInt(argv[1], PORT_LEN, 1025, 65535)) == 0 )
		exit(1);
}


void SocketUtils_createSocket(int *sock_fd)
{
	/**
	 * validating open socket
	 */
	if ( (*sock_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0 )
	{
		printf("Error opening socket.\n");
		exit(1);
	}
}






