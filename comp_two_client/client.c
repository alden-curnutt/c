/*
 * main.c
 *
 *  Created on: Jul 21, 2017
 *      Author: acurnutt
 */

#include "client.h"

int main( int argc, char **argv )
{
	long port_no = 0; // end point for user's input


	SocketUtils_countArgs(argc, 3, "Usage: comp_two_server [valid ip_v4 address] [port]\n");

	SocketUtils_validatePort( argv[2], &port_no, 1025, 65535 );
}
