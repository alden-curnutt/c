/*
 * volume.c
 *
 *  Created on: Jul 6, 2017
 *      Author: Alden J. Curnutt
 */

#include "CalcSquareVolume.h"

void calcVolume()
{
	/**
	 * Asks user for cube's side length, sanitizes input
	 * and calculates the cube's volume
	 */
	printf("\n┌───────────────────────┐\n");
	printf("│      Cube Volume      │\n");
	printf("└───────────────────────┘\n");


	float dblChoice = 0; // end point for user's input
	float volume = 0;
	char * userChoice = 0;
	userChoice = (char *)calloc(MAX_CHOICE_LEN, sizeof(char));

	do {
		printf("Enter length of a cube's side\n> ");
		dblChoice = validateDbl(userChoice, MAX_CHOICE_LEN, 1, 1);
	} while ( dblChoice == 0.0 );

	volume = dblChoice * dblChoice * dblChoice;
	printf("Cube volume is %.2lf\n\n", volume);

	record(volume, 2); // record volume in file

	//TODO: Remove while loop construct, remove state variable; remove printMainMenu
	free(userChoice);
}
