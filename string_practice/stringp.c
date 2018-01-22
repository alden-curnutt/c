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

/// TODO 6) Define myStrlen() here
/*copy your myStrlen prototype here{*/

size_t myStrlen( char *ptr )
{
	/// TODO 7) Declare and initialize the return variable | done
	size_t bytes = 0;
	int x = 42;

	int *y = (int *)ptr;
	x = *y;

	/// TODO 8) Calculate the size of your string | done
	while (1)
	{
		//if ( ptr[bytes] == '\0' )
		if ( *ptr == '\0' )
		{
			break;
		}
		else {
			bytes = bytes + 1;
			ptr = ptr + 1;
		}
	}
	/// TODO 9) Return the size. | done
	return bytes;
}



/*
 * myStrncpy notes:
 * -Be aware that strncpy copies AT MOST n bytes from the source to the destination.
 * --If the source has fewer bytes, then copy that amount.
 * --strncpy may not copy the NULL byte if n is smaller than strlen(src).
 * 		This behavior is acceptable for your implementation (just reinvent the wheel, don't improve it).
 * Hint: Your myStrlen() function may be useful here...
 */

/// TODO 10) Define myStrncpy() here
/*copy your myStrncpy prototype here{*/

	/// TODO 11) Declare and initialize the counter and max number of characters to copy.

	/// TODO 12) Set the maximum number of characters to copy. *hint* You can use your myStrlen function.

	/// TODO 13) Perform the copy.

	/// TODO 14) What do we return? Refer to your .h file.
//}



int main(void){
	char myStr[] = "Hello";

	/// TODO 3) Declare and initialize a char pointer to a destination string | done
	char *ptr;
	size_t numBytes = 0;

	// Some diagnostics. Print out the string.
	// Print out both strlen outputs for comparison.
	printf("String: %s\n", myStr);
	printf("Strlen: %u\n", (unsigned int)strlen(myStr));

	numBytes = myStrlen(myStr);

	printf("MyStrlen (numBytes): %lu\n", numBytes);



	/// TODO 4) Allocate and clear space for the destination string.
	///			DON'T FORGET TO CAST.
	// (cast)calloc(...)

	ptr = (char *)calloc(numBytes, sizeof(char));
	printf("size of ptr: %lu\n", sizeof(ptr));
	printf("size of myStr: %lu\n", sizeof(myStr));

	/// TODO Error checking. (replace /*buffer*/)
//	if(!/*buffer*/){
//		printf("Calloc failed\n");
//		exit(EXIT_FAILURE);
//	}

	/// TODO 5) Test your string copy. Replace "dest" with the name of your pointer.
	// dest = myStrncpy(dest, myStr, myStrlen(myStr));
	// printf("Dest: %s\n", dest);

	/// TODO 6) Free and NULL your pointer.


	return 0;
} // main












