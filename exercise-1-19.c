/**
 * Exercise 1-19
 *
 * Write a function myreverse(s) that myreverses the character
 * string s. Use it to write a program that myreverses its
 * input a line at a time.
 */
#include <stdio.h>

#define MAXLINE 1000

int mygetline(char line[], int lim);
void myreverse(char from[], char to[], int len);

int main()
{
	int len;
	char line[MAXLINE];
	char rline[MAXLINE];

	printf("> ");
	while ((len = mygetline(line, MAXLINE)) > 0)
	{
		myreverse(line, rline, len);
		printf("%s", rline);
		printf("> ");
	}

	return 0;
}

int mygetline(char s[], int lim)
{
	int c, i;

	for (i=0; i<lim-1 && (c = getchar())!='\n'; ++i)
		s[i] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';

	return i;
}

void myreverse(char s[], char t[], int lim)
{
	int i, j;

	i = lim-2;
	j = 0;
	while (j < lim-1)
		t[j++] = s[i--];
	t[j++] = '\n';
	t[j] = '\0';
}
