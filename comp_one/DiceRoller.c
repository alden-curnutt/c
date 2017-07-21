/*
 * dice_roller.c
 *
 *  Created on: Jul 6, 2017
 *      Author: Alden J. Curnutt
 */

#include "DiceRoller.h"

void diceRoller()
{
	/**
	 * Receives input for N rolls
	 * of N dice with N sides
	 */
	printf("\n┌───────────────────────┐\n");
	printf("│      Dice Roller      │\n");
	printf("└───────────────────────┘\n");

	long dice = 0, sides = 0, rolls = 0;
	char * userChoice = 0;
	userChoice = (char *)calloc(MAX_CHOICE_LEN, sizeof(char));

	// getting # of dice
	do {
		printf("How many dice will you roll? [Bounds: min|1    max|99]\n> ");
		dice = (validateInt(userChoice, MAX_CHOICE_LEN, 1, 99));
	} while ( dice == 0 );

	// getting # of sides per die
	do {
		printf("How many sides will each dice have? [Bounds: min|1    max|99]\n>");
		sides = (validateInt(userChoice, MAX_CHOICE_LEN, 1, 99));
	} while ( sides == 0 );

	// lol
	if ( dice == 1 && sides == 2 )
		printf("Aren't you flipping a coin?\n\n");

	// getting # of rolls
	do {
		printf("How many times will you roll? [Bounds: min|1    max|99]\n>");
		rolls = (validateInt(userChoice, MAX_CHOICE_LEN, 1, 99));
	} while ( rolls == 0 );

	printf("Dice: %ld      Sides: %ld      Rolls: %ld\n", dice, sides, rolls);
	printf("─────────────────────────────────────\n");

	// print dice roll results
	for ( int i = 1; i <= dice; i++ )
	{
		printf("Dice #%d: ", i);
		for ( int j = 0; j < rolls; j++ )
		{
			printf("%ld ", rand() % sides+1 );
		}
		printf("\n\n");
	}
	//TODO: remove circular references to printMainMenu; keep that inside main
	//TODO: fix use after free bug created by this free inside while loop.  While loop itself is not necessary here since you are only running this one time.
	//TODO: state is an unnecessary variable, use while(1) instead and break when you need out of the loop
	free(userChoice);
}
