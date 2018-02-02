/*
 * NewUtils.h
 *
 *  Created on: Dec 5, 2017
 *      Author: acurnutt
 */

#ifndef NEWUTILS_H_
#define NEWUTILS_H_

void StdUtils_flushStdin( char *str );
int StdUtils_isInt(long *portNo, char *str, int buffSize, int min, int max);
long StdUtils_isIntFromInput(char *str, int buffSize, int min, int max);
float StdUtils_isDblFromInput(char *str, int buffSize, int min, int max);

#endif /* NEWUTILS_H_ */
