/**
 * Exercise 1-21
 *
 * Write a program entab that replaces strings of blanks
 * by the minimum number of tabs and blanks to achieve
 * the same spacing. Assume a fixed set of tab stops,
 * say every n columns. Should n be a variable or a
 * symbolic parameter?
 */
#include <stdio.h>

#define MAXLINE 1000
#define NSPACES 2

int mygetline(char line[], int lim);
void entab(char line[], int lim);

int main()
{
	int len;
	char line[MAXLINE];

	printf("> ");
	while ((len = mygetline(line, MAXLINE)) > 0)
	{
		entab(line, len);
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
	if (c =='\n')
		s[i++] = c;
	s[i] = '\0';

	return i;
}

void entab(char s[], int lim)
{
	int i, j, ns;

	ns = 0;
	for (i = 0; i < lim; ++i)
	{
		if (s[i] == ' ' && ++ns == NSPACES)
		{
			for (j = i+1; j <= lim; ++j)
				s[j-NSPACES+1] = s[j];

			s[i-NSPACES+1] = '\t';
			lim -= NSPACES-1;
			ns = 0;
		}
	}
}
