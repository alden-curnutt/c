/*
 * main.c
 *
 *  Created on: Jun 27, 2017
 *      Author: Alden J. Curnutt
 */

#include "main.h"

void printMainMenu()
{
	/**
	 * Print program's root menu
	 */
	printf("┌───────────────────────┐\n");
	printf("│  COMP 1 - Randomizer  │\n");
	printf("├───────────────────────┤\n");
	printf("│  choose an option:    │\n");
	printf("└───────────────────────┘\n");
	printf("   1: Dice Roller\n");
	printf("   2: Circle Surface Area\n");
	printf("   3: Cube volume\n");
	printf("   4: Letter Histogram\n");
	printf("   5: Quit Program\n   >_ ");
}


int main()
{
	char * userChoice = {0}; // buffer containing user string
	long longChoice = 0; // endpoint for user's input
	time_t t;
	srand((unsigned) time(&t)); // seeding srand

	// TODO: allocate space for userChoice
	// TODO: learn about TO DO's.
	system("clear");

	while( 1 )
	//TODO:  change to while(1) and use a break to escape loop
	{
		printMainMenu();
		userChoice = (char *)calloc(MAX_CHOICE_LEN, sizeof(char));

		do {
			longChoice = (validateInt(userChoice, MAX_CHOICE_LEN, 1, 5));
		} while ( longChoice == 0 );  //ValidateInt returns long, you are checking for a float here

		switch ( longChoice )
		{
			case (1):
				diceRoller();
				break;
			case (2):
				calcSurfaceArea();
				break;
			case (3):
				calcVolume();
				break;
			case (4):
				calcHistogram();
				break;
			case (5):
				printf("\n┌───────────────────────┐\n");
				printf("│ Ending program . . .  │\n");
				printf("└───────────────────────┘\n");

				free(userChoice);
				exit(0);
				//TODO: Use break! and Call Exit.
		}
	}
}















