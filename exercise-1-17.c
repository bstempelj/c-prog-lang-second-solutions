/**
 * Exercise 1-17
 *
 * Write a program to print all input lines that are
 * longer than 80 characters.
 */
#include <stdio.h>

#define MAXLINE 1000
#define PRINTLIM 80

int mygetline(char line[], int lim);

int main()
{
	int len;
	char line[MAXLINE];

	while ((len = mygetline(line, MAXLINE)) > 0)
		if (len > 80)
			printf("%s", line);

	return 0;
}

int mygetline(char s[], int lim)
{
	int c, i;

	for (i=0; i<lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';

	return i;
}
