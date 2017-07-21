/*
 * StdUtils.h
 *
 *  Created on: Jul 18, 2017
 *      Author: acurnutt
 */

#ifndef STDUTILS_H_
#define STDUTILS_H_

void StdUtils_flushStdin( char *str );
long StdUtils_checkInt();
long StdUtils_checkIntFromInput();
float StdUtils_checkDbl(char *str, int buffSize, int min, int max);

#endif /* STDUTILS_H_ */
