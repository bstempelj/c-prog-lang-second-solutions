#include <stdio.h>

#define nspaces 4

int getline(char s[]);

int main()
{
  int len;
  int i, j, found;
  char line[1000];
  char newline[1000];

  while (len = getline(line))
  {
    found = 0;
    for (i = j = 0; i < len; i++)
    {
      if (line[i] == ' ')
      {
        if (++found == nspaces)
        {
          newline[j++] = '\t';
          found = 0;
        }
      }
      else
      {
        newline[j++] = line[i];
        found = 0;
      }
    }
  }

  return 0;
}

int getline(char s[])
{
  int c, i;

  for (i = 0; (c = getchar()) != EOF && c != '\n'; i++)
    s[i] = c;

  return i;
}