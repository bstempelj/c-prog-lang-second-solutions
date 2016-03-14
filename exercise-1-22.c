#include <stdio.h>

#define FOLD 10

int getline(char s[])
{
  int c, i;

  for (i = 0; (c = getchar()) != EOF && c != '\n'; i++)
    s[i] = c;
  if (c == '\n')
    s[i++] = c;
  s[i] = '\0';
  return i;
}

int main()
{
  int len, i, j;
  char line[80];

  while (len = getline(line))
  {
    if (len > FOLD)
    {
      j = 2;
      i = FOLD;
      while (i <= len)
      {
        while (line[i] != ' ')
          i--;
        line[i] = '\n';
        i = j * FOLD;
        j++;
      }
    }
  }

  return 0;
}