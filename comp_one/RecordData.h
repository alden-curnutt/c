/*
 * record.h
 *
 *  Created on: Jul 6, 2017
 *      Author: Alden J. Curnutt
 */

#ifndef RECORDDATA_H_
#define RECORDDATA_H_

#include <stdio.h>

#define DB "/tmp/randomizer_results.txt"
#define COLOR_GREEN "\x1b[32m"
#define COLOR_RESET "\x1b[0m"

void record(float dataToWrite, int flag);

#endif /* RECORDDATA_H_ */
