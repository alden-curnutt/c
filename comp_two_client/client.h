/*
 * main.h
 *
 *  Created on: Jul 21, 2017
 *      Author: acurnutt
 */

#ifndef MAIN_H_
#define MAIN_H_

#include "StdUtils.h"
#include "SocketUtils.h"

#include <unistd.h>
#include <string.h>

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MIN_PORT 1025
#define MAX_PORT 65535
#define COLOR_GREEN "\x1b[32m"
#define COLOR_RESET "\x1b[0m"

#endif /* MAIN_H_ */
