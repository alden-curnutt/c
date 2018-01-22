/*
 * stringp.h
 *
 *  Created on: Jan 16, 2018
 *      Author: acurnutt
 */

#ifndef STRINGP_H_
#define STRINGP_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/// TODO 1) Declare myStrlen prototype. | done
/*[type] myStrlen([arg1]);
 *
 * REQUIREMENTS:
 * myStrlen should return a special type reserved for size representing the size of the string.
 * This special type is "size_t".
 * arg 1 is a char pointer to the buffer containing the string
 *
 */

size_t myStrlen( char *ptr );

/// TODO 2) Declare myStrncpy prototype | done
/*[type] myStrncpy([arg1], [arg2], [arg3]);
 *
 * REQUIREMENTS:
 * myStrncpy should return a pointer to the destination string.
 * arg 1 is a char pointer to the destination string.
 * arg 2 is a const char pointer to the source string.
 * arg 3 is a size_t representing the max number of bytes to copy.
 */

char * myStrncpy( char *destStringPtr, const char* sourceStringPtr, size_t numBytesToCpy );


#endif /* STRINGP_H_ */
