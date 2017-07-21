/*
 * histogram.c
 *
 *  Created on: Jul 6, 2017
 *      Author: Alden J. Curnutt
 */

#include "WordHistogram.h"

void calcHistogram()
{
	/**
	 * Receive input to newline and count
	 * the number of letters in each word, then
	 * print out a letter count histogram
	 */
	printf("\n┌───────────────────────┐\n");
	printf("│       Histogram       │\n");
	printf("└───────────────────────┘\n");
	printf("Enter your favorite sentence\n> ");

	int c = 0, count = 0, inWord = FALSE;
	char *wordLength = 0; // holds the word length counts
	wordLength = (char *)calloc(MAX_CHOICE_LEN, sizeof(char));

	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t' || c == '\n' ) {  //TODO:  Check for '\r' as well since its used in Windows and windows like things
			if (inWord == TRUE) {
				if (count <= MAX_CHOICE_LEN) // if word is larger than MAX_CHOICE_LEN
					wordLength[count-1]++;   //TODO: Off-by-One bug
				else
					wordLength[MAX_CHOICE_LEN]++;
				inWord = FALSE;
			}
			if ( c == '\n' )
				break;
		}
		else {
			if (inWord == FALSE) {
				count = 0;
				inWord = TRUE;
			}
			count++;
		}
	}

	for ( int i = 0; i < MAX_CHOICE_LEN; i++ ) // printing out the histogram
		printf("%*d│%d\n", 2, i+1, wordLength[i]);

	free(wordLength);
}
