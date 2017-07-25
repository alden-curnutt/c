/*
 * StdUtils.h
 *
 *  Created on: Jul 18, 2017
 *      Author: acurnutt
 */

#ifndef STDUTILS_H_
#define STDUTILS_H_

void StdUtils_flushStdin( char *str );
long StdUtils_isInt(char *str, int buffSize, int min, int max);
long StdUtils_isIntFromInput();
float StdUtils_isDblFromInput(char *str, int buffSize, int min, int max);

#endif /* STDUTILS_H_ */
