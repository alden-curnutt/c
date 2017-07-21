/*
 * record.c
 *
 *  Created on: Jul 6, 2017
 *      Author: Alden J. Curnutt
 */

#include "RecordData.h"

void record(float dataToWrite, int flag)
{
	/**
	 * Receives data and writes to
	 * /tmp/randomizer_results.txt
	 */
	FILE *file;

	file = fopen(DB, "a");
	if (file == NULL)
	{
		printf("Error recording result data\n");
		return;
	}

	if ( flag == 1 )
		fprintf(file, "Circle surface area is: ");
	else if ( flag == 2 )
		fprintf(file, "Cube volume is: ");

	fprintf(file, "%.2f\n", dataToWrite);
	printf("(results have been saved to " COLOR_GREEN "%s" COLOR_RESET")\n\n", DB);

	fclose(file);
}
