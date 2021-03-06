/*
 * getlinep.h
 *
 *  Created on: Jan 23, 2018
 *      Author: acurnutt
 */

#ifndef GETLINEP_H_
#define GETLINEP_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <signal.h>

#define BUFFINC 16
#define MAXBUFFSIZE 1024
#define SIGINT 2

/// TODO 1) Declare myGetLine prototype. | done

size_t myGetLine( char **endString, unsigned int endSize );

/*[type] myGetLine([arg1], [arg2]);
 *
 * REQUIREMENTS:
 * myGetLine should return the number of bytes read (which may not be the same as buffer size!).
 * arg 1 is a double char pointer to the buffer which will contain the final string
 * arg 2 is an unsigned int pointer representing the final size of our allocated buffer
 *
 * Hint: arg1 will point to another pointer, which in turn points to our buffer.
 *
 */

int stringContains(char * string, char theChar);
void exitOnFailure(const char * message, char * buffer);
void signalHandler();

#endif /* GETLINEP_H_ */
