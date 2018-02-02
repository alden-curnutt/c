/*
 * structures.c
 *
 *  Created on: Dec 4, 2017
 *      Author: acurnutt
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/queue.h>

#include "structures.h"

struct node
{
	char c;
	int i;

	TAILQ_ENTRY(node) nodes;
};



int main(int argc, char **argv)
{
	TAILQ_HEAD(head_s, node) head;

	TAILQ_INIT(&head);

	char string[] = "Hello World\n";
	int num = 0;


	struct node *e = NULL;
	int c;

	for ( c = 0; c < strlen(string); c++ )
	{
		num = num + 1;
		e = malloc( sizeof(struct node) );

		if ( e == NULL )
		{
			printf("malloc failed\n");
			exit(EXIT_FAILURE);
		}

		e -> c = string[c];
		e -> i = num;

		TAILQ_INSERT_TAIL( &head, e, nodes );
		e = NULL;
	}


	TAILQ_FOREACH( e, &head, nodes )
	{
		if ( e -> c == ' ' )
		{
			printf("Struct #%d -> [space]\n", e -> i);
		}
		else if ( e -> c != '\n' )
		{
			printf("Struct #%d -> %c\n", e -> i, e -> c);
		}

	}


	while ( !TAILQ_EMPTY(&head) )
	{
		e = TAILQ_FIRST(&head);
		TAILQ_REMOVE( &head, e, nodes );
		free(e);
		e = NULL;
	}


	return EXIT_SUCCESS;
}
