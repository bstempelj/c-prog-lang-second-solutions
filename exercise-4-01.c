/*******************************************************************************
Exercise 4-1: Write the function strrindex(s,t), which return the position of
the rightmost occurrence of t in s, or -1 if there is none.
*******************************************************************************/

#include <stdio.h>
#define MAXLINE 1000

int getline(char line[], int max);
int strindex(char source[], char searchfor[]);

char pattern[] = "ould";

int main()
{
    char line[MAXLINE];
    int found = 0;

    while (getline(line, MAXLINE) > 0)
        if (strrindex(line, pattern) >= 0)
        {
            printf("%s\n", line);
            found++;
        }
    return found;
}

int getline(char s[], int lim)
{
    int c, i;

    i = 0;
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

int strrindex(char s[], char t[])
{
    int i, j, k;
    int fi = -1;     /* found index */

    for (i = 0; s[i] != '\0'; i++)
    {
        for (j = i, k = 0; t[k] != '\0' && s[j]==t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            fi = i;
    }
    return fi;
}