/**
 * Exercise 1-13
 *
 * Write a program to print a histogram of the lengths
 * of words in its input. It is possible to choose
 * between vertical and horizontal type histograms.
 */
#include <stdio.h>

#define SIZE 30
#define VERT 1

main()
{
	int c, i, j, nc, ncmax, end;
	int nwords[SIZE];
	
	for (i = 0; i < SIZE; ++i)
		nwords[i] = 0;
	
	ncmax = nc = i = 0;
	while ( ((c = getchar()) != EOF) && i < SIZE )
	{
		++nc;
		
		if (c == ' ' || c == '\n' || c == '\t')
		{
			nwords[i++] = --nc;
			if (nc > ncmax)
				ncmax = nc;

			nc = 0;
		}
	}
	
	end = i;	
	if (VERT)
	{

		while (ncmax > 0)
		{
			for (i = 0; i < end; ++i)
			{
				if (nwords[i] == ncmax)
				{
					putchar('#');
					--nwords[i];
				}
				else
					putchar(' ');			
			}
		
			putchar('\n');
			--ncmax;
		}
	}
	else
	{
		for (i = 0; i < end; ++i)
		{
			for (j = 0; j < nwords[i]; ++j)
				putchar('#');
			putchar('\n');
		}
	}
	
}
