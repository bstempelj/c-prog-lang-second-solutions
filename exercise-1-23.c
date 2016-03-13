/******************************************************
Exercise 1-23: Write a program to remove all comments
from a C program. Don't forget to handle quoted strings
and character constants properly. C comments do not nest.
*******************************************************/

#include <stdio.h>

int getline(char s[])
{
  int c, i;

  for (i = 0; (c = getchar()) != EOF && c != '\n'; i++)
  {
    s[i] = c;
  }
  s[i] = '\0';

  return i;
}

int main()
{
  int i, j, len, found;
  char line[80];
  char new_line[80];

  found = 0;
  while (len = getline(line))
  {
    for (i = j = 0; i < len; i++)
    {
      if (line[i] == '/' && line[i + 1] == '*')
      {
        found = 1;
      }
      else if (line[i - 1] == '*' && line[i] == '/')
      {
        found = 0;
      }
      else if (found == 0)
      {
        new_line[j++] = line[i];
      }
    }
  }

  return 0;
}