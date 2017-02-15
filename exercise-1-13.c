/**
 * Exercise 1-13
 *
 * Write a program to print a histogram of the lengths
 * of words in its input.
 */
#include <stdio.h>

#define SIZE 30

main()
{
	int c, i, j, nc, end;
	int nwords[SIZE];
	
	for (i = 0; i < SIZE; ++i)
		nwords[i] = 0;
	
	nc = i = 0;
	while ( ((c = getchar()) != EOF) && i < SIZE )
	{
		++nc;
		
		if (c == ' ' || c == '\n' || c == '\t')
		{
			nwords[i++] = nc-1;
			nc = 0;
		}
	}
	
	end = i;
	for (i = 0; i < end; ++i)
	{
		printf("%2d: ", i);
		for (j = 0; j < nwords[i]; ++j)
			putchar('#');
		putchar('\n');
	}	
}
