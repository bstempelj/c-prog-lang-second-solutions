/**
 * Exercise 1-20
 *
 * Write a program detab that replaces tabs in the input
 * with the proper number of blanks to space to the next
 * tab stop. Assume a fixed set of tabs stops, say every
 * n columns. Should n be a variable or a symbolic
 * parameter?
 */
#include <stdio.h>

#define MAXLINE 1000
#define NSPACES 4

int mygetline(char line[], int lim);
void detab(char line[], int len);

int main()
{
	int len;
	char line[MAXLINE];
	char mline[MAXLINE];

	printf("> ");
	while ((len = mygetline(line, MAXLINE)) > 0)
	{
		detab(line, len);
		printf("%s", line);
		printf("> ");
	}

	return 0;
}

int mygetline(char s[], int lim)
{
	int c, i;

	for (i=0; i<lim-1 && (c=getchar())!='\n'; ++i)
		s[i] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';

	return i;
}

void detab(char s[], int len)
{
	int i, j;

	for (i = 0; i < len; ++i)
	{
		if (s[i] == '\t')
		{
			/* move char forward for NSPACES */
			for (j = len; j > i; --j)
			{
				s[j+NSPACES-1] = s[j];
			}
			/* instead of tab add NSPACES of spaces */
			j += NSPACES;
			while (--j >= i)
				s[j] = '_';
			/* length of line has been increased */
			len += NSPACES-1;
		}
	}
}
