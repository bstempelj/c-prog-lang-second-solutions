/**
 * Exercise 1-18
 *
 * Write a program to remove trailing blanks and tabs from
 * each line of input, and to delete entirely blank line.
 */
#include <stdio.h>

#define MAXLINE 1000

int mygetline(char line[], int lim);
int process(char line[], int len);

int main()
{
	int len;
	char line[MAXLINE];

	printf("> ");
	while ((len = mygetline(line, MAXLINE)) > 0)
	{
		len = process(line, len);
		printf("%s", line);
		printf("> ");
	}

	return 0;
}

int mygetline(char s[], int lim)
{
	int c, i;

	for (i=0; i<lim-1 && (c = getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';

	return i;
}

int process(char s[], int len)
{
	int i;

	i = len-2;
	while (s[i] == ' ' || s[i] == '\t')
		--i;
	s[++i] = '\n';
	s[++i] = '\0';

	return i;
}
