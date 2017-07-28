/*
 * SocketUtils.c
 *
 *  Created on: Jul 18, 2017
 *      Author: acurnutt
 */

#include "SocketUtils.h"


void SocketUtils_countArgs( int argc, int requiredCount, char msg[] )
{
	/**
	 * testing argument count
	 */
	if ( argc != requiredCount )
	{
		printf("%s", msg);
		exit(1);
	}
}


void SocketUtils_validatePort( char *argv, long *port_no, long min, long max )
{
	/**
	 * validating port in range
	 *     exits execution if port is not valid
	 */
	if ( (*port_no = StdUtils_isInt(argv, PORT_LEN, min, max)) == 0 )
	{
		printf("[port]\n");
		exit(1);
	}
}


void SocketUtils_validateAddress( char *argv, char address )
{
	/**
	 * validating port in range
	 *     exits execution if port is not valid
	 */
//	if ( (*port_no = StdUtils_isInt(argv, PORT_LEN, min, max)) == 0 )
//	{
//		printf("[port]\n");
//		exit(1);
//	}
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






