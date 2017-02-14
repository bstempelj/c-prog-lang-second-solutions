#include <stdio.h>

#define nspaces 4

int add_nspaces(char s[], int start);
int getline(char s[]);

int main()
{
  int len;
  int i, j;
  char line[1000];
  char newline[1000];

  while (len = getline(line))
  {
    for (i = j = 0; i < len; i++)
      if (line[i] == '\t')
        j = add_nspaces(newline, j);
      else
        newline[j++] = line[i];
  }

  return 0;
}

int add_nspaces(char s[], int start)
{
  int i;

  for (i = 0; i < nspaces; i++)
    s[start++] = ' ';

  return start;
}

int getline(char s[])
{
  int c, i;

  for (i = 0; (c = getchar()) != EOF && c != '\n'; i++)
    s[i] = c;

  return i;
}