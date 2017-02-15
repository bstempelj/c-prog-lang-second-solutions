/**
 * Exercise 1-14
 *
 * Write a program to print a histogram of the frequencies
 * of different characters in its input.
 */
#include <stdio.h>

#define SIZE 128
#define VERT 0

main()
{
	int c, i, j, max;
	int fchars[SIZE];
	
	for (i = 0; i < SIZE; ++i)
		fchars[i] = 0;
	
	max = i = 0;
	while ((c = getchar()) != EOF)
	{
		++fchars[c];
		if (fchars[c] > max)
			max = fchars[c];
	}
	
	if (VERT)
	{

		while (max > 0)
		{
			for (i = 0; i < SIZE; ++i)
			{
				if (fchars[i] >= max)
					putchar('#');
				else if (fchars[i] != 0)
					putchar(' ');			
			}		
			if (max > 1)
				putchar('\n');

			--max;
		}
	}
	else
	{
		for (i = 0; i < SIZE; ++i)
		{
			if (fchars[i] != 0)
			{
				printf("%c:", i);
				for (j = 0; j < fchars[i]; ++j)
					putchar('#');
				putchar('\n');
			}
		}
	}
	
}
