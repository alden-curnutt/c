/*
 * server.h
 *
 *  Created on: Dec 4, 2017
 *      Author: acurnutt
 */

#ifndef SERVER_H_
#define SERVER_H_

#include <stdio.h>

#include <sys/queue.h>
#include <sys/socket.h>
#include <sys/types.h>

#include <netinet/in.h>

#include <StdUtils.h>
#include <SocketUtils.h>

#define MIN_PORT 1
#define MAX_PORT 1024
#define MAX_CLIENTS 10


void startChat(int serverFd);

#endif /* SERVER_H_ */
