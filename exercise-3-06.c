/*******************************************************************************
Exercise 3-6: Write a version of itoa that accepts three arguments instead of
two. The third argument is a minimum field width; the converted number must be
padded with blanks on the left if necessary to make it wide enough.
*******************************************************************************/

#include <stdio.h>

void reverse(char s[])
{
    int c, i, j;

    for (i = 0, j = strlen(s)-1; i < j; i++, j--)
        c = s[i], s[i] = s[j], s[j] = c;
}

void itoa(int n, char s[], int w)
{
    int i, sign;

    if ((sign = n) < 0)
        n = -n;
    i = 0;
    do
    {
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);
    if (sign < 0)
        s[i++] = '-';

    while (i <= w)
        s[i++] = ' ';
    s[i] = '\0';

    reverse(s);
}

int main()
{
    char s[100];
    char t[] = "Hello";
    char v[] = {'H', 'e', 'l', 'l', 'o', '\0'};

    itoa(120, s, 10);
    printf("%s\n", s);

    printf("t: %d\n", strlen(t));
    printf("v: %d\n", strlen(v));

    return 0;
}