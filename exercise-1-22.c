/**
 * Exercise 1-22
 *
 * Write a program to "fold" long input lines into two
 * or more shorter lines after the last non-blank character
 * that occurs before the n-th column of input. Make sure
 * your program does something intelligent with very long
 * lines, and if there are no blanks or tabs before the
 * specified column.
 */
#include <stdio.h>

#define MAXLINE 1000
#define WORDWRAP 4

int mygetline(char line[], int lim);
void movechars(char line[], int start, int end);
void wrapline(char line[], int len);

int main()
{
	int len;
	char line[MAXLINE];

	printf("> ");
	while ((len = mygetline(line, MAXLINE)) > 0)
	{
		wrapline(line, len);
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

void movechars(char s[], int start, int end)
{
	for (int i = end; i >= start; --i)
		s[i+1] = s[i];
}

void wrapline(char s[], int len)
{
	int i = WORDWRAP;

	while (i < len)
	{
		// find first blank or tab
		while (s[i] != ' ' && s[i] != '\t' && s[i] != '\n' && i > 0)
			--i;
		// no blanks or tabs found
		if (i == 0 || s[i] == '\n')
		{
			if (i == 0)
				i += WORDWRAP;
			else
				i += WORDWRAP+1;
			movechars(s, i, len);
		}

		s[i++] = '\n';
		i += WORDWRAP;
		len++;
	}
}











