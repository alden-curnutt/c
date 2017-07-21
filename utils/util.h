/*
 * util.h
 *
 *  Created on: Jul 8, 2017
 *      Author: acurnutt
 */

#ifndef UTIL_H_
#define UTIL_H_

void flushStdin( char *str );
long validateInt();
long validateIntInput();
float validateDbl(char *str, int buffSize, int min, int max);

#endif /* UTIL_H_ */
