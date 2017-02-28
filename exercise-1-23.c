/**
 * Exercise 1-23
 *
 * Write a program to remove all comments from a C program.
 * Don't forget to handle quoted strings and character
 * constants properly. C comments do not nest.
 */
#include <stdio.h>

#define MAXLINE 1000

int mygetline(char line[], int lim);
void nocomments(char old[], char new[]);

int main()
{
	int len;
	char line[MAXLINE];
	char newline[MAXLINE];	// line with no comments

	printf("> ");
	while ((len = mygetline(line, MAXLINE)) > 0)
	{
		nocomments(line, newline);
		printf("%s", newline);
		printf("> ");
	}
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

// suppose that comments are not nested
// and user does not use */ without first
// using */
void nocomments(char old[], char new[])
{
	int i, j;
	int lcom;	// inside line comment
	int bcom;	// inside block comment

	i = j = 0;
	lcom = bcom = 0;
	while (old[i] != '\0')
	{
		if (old[i] == '/' && old[i+1] == '/')
			lcom = 1;

		if (!lcom)
		{
			if (old[i] == '/' && old[i+1] == '*')
				bcom = 1;
			else if (old[i] == '/' && old[i-1] == '*' && bcom)
				bcom = 0;
			else if (!bcom)
				new[j++] = old[i];
		}

		++i;
	}

	if (lcom || bcom)
		new[j++] = '\n';
	new[j] = '\0';
}
