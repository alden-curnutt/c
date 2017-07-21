/*
 * SocketUtils.h
 *
 *  Created on: Jul 18, 2017
 *      Author: acurnutt
 */

#ifndef SOCKETUTILS_H_
#define SOCKETUTILS_H_

#include <stdio.h>
#include <stdlib.h>

#include <sys/socket.h>

#include "StdUtils.h"

#define PORT_LEN 4

void SocketUtils_countArgs( int argc );
void SocketUtils_checkPort( char **argv, long *port );
void SocketUtils_createSocket(int *sock_fd);

#endif /* SOCKETUTILS_H_ */
