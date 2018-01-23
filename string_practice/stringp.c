/*
 * stringp.c
 *
 *  Created on: Jan 16, 2018
 *      Author: acurnutt
 */

#include "stringp.h"

/*
 * myStrlen notes:
 * This is an extremely easy function to code. It can be done in as little as three lines.
 * However that doesn't mean you need to do it in three. Just make sure it's as
 * simple as possible while still being fully functional.
 */

/// TODO 6) Define myStrlen() here | done

size_t myStrlen( char *ptr )
{
	/// TODO 7) Declare and initialize the return variable | done
	size_t bytes = 0;

	/// TODO 8) Calculate the size of your string | done
	while ( *ptr != '\0' )
	{
		bytes = bytes + 1;
		ptr = ptr + 1;
	}
	/// TODO 9) Return the size. | done
	return bytes + 1;
}



/*
 * myStrncpy notes:
 * -Be aware that strncpy copies AT MOST n bytes from the source to the destination.
 * --If the source has fewer bytes, then copy that amount.
 * --strncpy may not copy the NULL byte if n is smaller than strlen(src).
 * 		This behavior is acceptable for your implementation (just reinvent the wheel, don't improve it).
 * Hint: Your myStrlen() function may be useful here...
 */

/// TODO 10) Define myStrncpy() here | done

/// TODO 11) Declare and initialize the counter and max number of characters to copy. | done

/// TODO 12) Set the maximum number of characters to copy. *hint* You can use your myStrlen function. | done

/// TODO 13) Perform the copy. | done

/// TODO 14) What do we return? Refer to your .h file. | done
char * myStrncpy( char *destStringPtr, const char* sourceStringPtr, size_t numBytesToCpy )
{
	for ( int i = 0; i < numBytesToCpy; i++ )
	{
		destStringPtr[i] = sourceStringPtr[i];
	}

	return destStringPtr;
}



int main(void){
	char myStr[] = "Hello";

	/// TODO 3) Declare and initialize a char pointer to a destination string | done
	char *destPtr = NULL;
	size_t numBytes = 0;


	// Some diagnostics. Print out the string.
	// Print out both strlen outputs for comparison.
	printf("String: %s\n", myStr);
	printf("Strlen: %u\n", (unsigned int)strlen(myStr));


	numBytes = myStrlen(myStr);


	printf("MyStrlen (numBytes): %lu (includes %c%d)\n", numBytes, '\\', 0);


	/// TODO 4) Allocate and clear space for the destination string.
	destPtr = (char *)calloc(numBytes, sizeof(char));
	if ( destPtr == NULL )
	{
		perror("calloc");
		exit(EXIT_FAILURE);
	}

	printf("destPtr value before myStrncpy: %s\n", destPtr);
	myStrncpy( destPtr, myStr, numBytes );

	printf("destPtr value after cpy: %s\n", destPtr);

	/// TODO 5) Test your string copy. Replace "dest" with the name of your pointer. | done
	// dest = myStrncpy(dest, myStr, myStrlen(myStr));
	// printf("Dest: %s\n", dest);
	/// TODO 6) Free and NULL your pointer. | done

	free(destPtr);
	destPtr = NULL;

	return 0;
} // end main












