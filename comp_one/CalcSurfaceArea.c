/*
 * surface_area.c
 *
 *  Created on: Jul 6, 2017
 *      Author: Alden J. Curnutt
 */

#include "CalcSurfaceArea.h"

void calcSurfaceArea()
{
	/**
	 * Asks user for circle radius, sanitizes input
	 * and calculates the circle's surface area
	 */
	printf("\n┌───────────────────────┐\n");
	printf("│ Circle Surface Area   │\n");
	printf("└───────────────────────┘\n");

	float dblChoice = 0; // var for converted input
	float area = 0; // stores cube's computed area
	char * userChoice = 0; // stores user's input
	userChoice = (char *)calloc(MAX_CHOICE_LEN, sizeof(char));

	do {
		printf("Enter a circle radius\n>");
		dblChoice = validateDbl(userChoice, MAX_CHOICE_LEN, 1, 1);
	} while ( dblChoice == 0.0 );

	area = PI * (dblChoice * dblChoice);
	printf("Cirle Surface Area is %.2lf\n\n", area);

	record(area, 1);

	//TODO:  Dont need a while loop, remove state variable
	free(userChoice);
}
