/*
 * getlinep.c
 *
 *  Created on: Jan 23, 2018
 *      Author: acurnutt
 */

#include "getlinep.h"

int main(){

	// signal handler, ignore this
	//signal(SIGINT, signalHandler);

	/// TODO 2) Declare and initialize to NULL a char pointer to our buffer, and a size variable | done
	char *buffer = NULL;
	size_t bytesRead = 0;

	int x = 1;

	while( x == 1){

		buffer = NULL;
		bytesRead = 0;


		//printf("Enter text: "); // prompt

		printf("in main, &buffer: %p\n", &buffer);
		printf("in main, buffer: %s\n", buffer);

		bytesRead = myGetLine( &buffer, bytesRead  );
		/// TODO 4) Test myGetLine by passing in an address to your pointer,
		///			thus "converting" it to a double pointer, and a pointer to your int
		// myGetLine(...);

		/// TODO 5) Print out your buffer to test if it has input.
		// printf(...);

		/// TODO 6) Don't forget to free and NULL your buffer afterwards.
		// free(...);

		x = x + 1;
	}

	return EXIT_SUCCESS;
} // main

/*
 * Some notes:
 * -The original SINGLE pointer may be pointing to NULL. Handle this case properly
 * --EX: if(*buf == NULL), then allocate new space for input
 * --If there isn't enough space in your current buffer for more text, reallocate
 * --How do we know how much space is allocated in a passed in non-NULL buffer?
 * --When I say "Pass in a buffer" I really mean "Pass in a pointer to a buffer"
 * -Feel free to use fgets() in this function. Refer to the MAN pages for usage.
 * -If the buffer is freed and not set to NULL (pointing to unallocated space)
 *  and bufSize is not zeroed, getline() will cause a SEGFAULT upon next memory access.
 *
 */

/// TODO 3) Define myGetLine() here | done
/*copy your myGetLine prototype here*/
size_t myGetLine( char **buffer, unsigned int bytesRead )
{

	/// Conceptual question: Why do we use a double pointer???
		/// A: so that the myGetLine function can store the string from stdin
		///    while also returning the num bytes read
	printf("in func, &buffer: %p\n", &buffer);
	printf("in func, buffer: %s\n", *buffer);
	printf("in func, *buffer: %p\n", *buffer);



	//int bytesRead = 0;
	//char * temp = NULL; // temp pointer for realloc error checking



	//if(*buf == NULL || *bufSize < INIT_SIZE){
		/// TODO A) Allocate INIT_SIZE bytes to your buffer.
		///			DON'T FORGET TO CAST.
		// (cast)calloc(...);

		/// TODO B) Error checking (replace "/*buffer*/")
		//if(!/*buffer*/){
		//	exitOnFailure("Calloc fail!", /*buffer*/);
		//}
		//*bufSize = INIT_SIZE;
	//}

	// loop until we get the newline
	//do{
		/// TODO C) Combined read from stdin and error checking
		//if(!fgets((/*buffer*/ + bytesRead), INIT_SIZE, stdin)){
			//exitOnFailure("fgets() fail!", /*buffer*/);
		//} // read in from stdin, exit on failure or unexpected EOF

		/// TODO D) Look for newline in our buffer
		//if(!strchr(/*buffer*/, '\n')){ // replace with the correct usage of "buf"

			//bytesRead = strlen(/*buffer*/);
			//*bufSize += INIT_SIZE;

			/// TODO E) Realloc, using temp to store a pointer to the buf for error checking.
			///			Dereference bufSize to use as a new size to realloc.
			// temp = (cast)realloc(...);

			/// TODO F) Error checking
			//if(!temp){
			//	exitOnFailure("realloc() fail!", /*buffer*/);
			//} // if realloc fail

			/// TODO G) Set our buffer to point to the same memory that temp is pointer to
			/*buffer*/ //= temp;

			/// TODO H) Zero out the memory here.
			///			Extra credit: Why do we do this?
			//bzero((/*buffer*/ + bytesRead), (size_t)INIT_SIZE);

		//} // if


		//else{
			/// TODO I) If newline is found we'll just update bytes read
			// bytesRead = ???
		//}

	//} while(!strchr(*buf, '\n'));

	/// TODO J) Return the number of bytes read

	return bytesRead;
} // myGetLine



/// @brief Exits, printing out an error message and freeing a single buffer.
//void exitOnFailure(const char * message, char * buffer){
//	printf("%s\n", message);
//	free(buffer);
//	buffer = NULL;
//	exit(EXIT_FAILURE);
//} // exitOnFailure



/// @brief Signal handler for exiting infinite while loop
//void signalHandler(int sigNum){
//	printf("\nQuitting...\n");
//	exit(0);
//} // signalHandler
