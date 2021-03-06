/*
 * NewUtils.c
 *
 *  Created on: Dec 5, 2017
 *      Author: acurnutt
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>

#include "NewUtils.h"

void StdUtils_flushStdin( char *str )
{
	/**
	 * Chew up input from stdin after max
	 * length of input has been reached
	 */
	if ( !strchr(str, '\n') )
		while(fgetc(stdin)!='\n');
}



int StdUtils_isInt(long *portNo, char *str, int buffSize, int min, int max)
{
	/**
	 * Validate input is a long
	 *     if valid, return the long value
	 *     if invalid, return 0
	 */
	char *endPtr = NULL;

	*portNo = strtol(str, &endPtr, 0);

	if ( *endPtr != '\0' && *endPtr != '\n' )
	{
		 printf("Entry is invalid ");
		 return 0;
	}
	if ( *portNo != 0 )
	{
		if ( *portNo < min || *portNo > max ) {
			printf("Entry is not a valid option ");
			return 0;
		}
		else
		{
			return 1;
		}
	}
	else
	{
		printf("Entry is not a valid option ");
		return 0;
	}
}



long StdUtils_isIntFromInput(char *str, int buffSize, int min, int max)
{
	/**
	 * Validate input is a long
	 *     if valid, return the long value
	 *     if invalid, return 0
	 */
	char *endptr = NULL;
	long result = 0;

	// read input from user
	fgets(str, buffSize, stdin);
	StdUtils_flushStdin(str);

	result = strtol(str, &endptr, 10);
	if ( result != 0 && endptr[0] == '\n' )
	{
		if ( result < min || result > max ) {
			printf("Entry is not a valid option\n");
			return 0;
		}
		else
			return result;
	}
	else
	{
		printf("Entry is not a valid option\n");
		return 0;
	}
}



float StdUtils_isDblFromInput(char *str, int buffSize, int min, int max)
{
	/**
	 * Validate input is a double
	 *     if valid, return the double value
	 *     if invalid, return 0.0
	 */
	char *endptr = NULL;
	float result = 0;

	// read input from user
	fgets(str, buffSize, stdin);
	StdUtils_flushStdin(str);

	result = strtod(str, &endptr);

	if ( result != 0 && endptr[0] == '\n' && result > 0 )
		return result;
	else
	{
		printf("Entry is not a valid option\n");
		return 0;
	}
}
