/*******************************************************************************
Exercise 2-10: Rewrite the function lower, which converts upper case letters
to lower case, with a conditional expression instead of if-else.
*******************************************************************************/

#include <stdio.h>

void lower(char s[])
{
  int i;

  for (i = 0; s[i] != '\0'; i++)
    s[i] = (s[i] >= 65 && s[i] < 97) ? s[i] + 97 - 65 : s[i];
}

int main()
{
  char s[] = "HONKI";
  lower(s);
  printf("%s", s);
}