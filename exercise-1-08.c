/**
 * Exercise 1-8
 *
 * Write a program to count blanks, tabs, and newlines.
 */
#include <stdio.h>

int main()
{
	int c, nb, nt, nl;

	nb = nt = nl = 0;
	while ((c = getchar()) != EOF) {
		if (c == ' ')
			++nb;
		else if (c == '\t')
			++nt;
		else if (c == '\n')
			++nl;
	}
	printf("blanks: %d\n", nb);
	printf("tabs: %d\n", nt);
	printf("newlines: %d\n", nl);
}
