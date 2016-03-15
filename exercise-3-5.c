/*******************************************************************************
Exercise 3-5: Write the function itob(n,s,b) that converts the integer n into a
base b character representation in the string s. In particual itob(n,s,16)
formats n as a hexadecimal integer in s.
*******************************************************************************/

#include <math.h>
#include <stdio.h>

void reverse(char s[])
{
    int c, i, j;

    for (i = 0, j = strlen(s)-1; i < j; i++, j--)
        c = s[i], s[i] = s[j], s[j] = c;
}

char tohex(int n)
{
    switch(n)
    {
        case 10: return 'A';
        case 11: return 'B';
        case 12: return 'C';
        case 13: return 'D';
        case 14: return 'E';
        case 15: return 'F';
        default: return n + '0';
    }
}

void itob(int n, char s[], int b)
{
    int i, sign;

    /* http://math.stackexchange.com/questions/408761/hexadecimal-value-of-a-negative-number */
    if (n < 0 && b == 16)
        n += pow(2, 16);
    else if ((sign = n) < 0)
        n = -n;

    i = 0;
    do
    {
        if (b == 16)
            s[i++] = tohex(n % b);
        else
            s[i++] = n % b + '0';
    } while (n /= b);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

int main()
{
    int n = 120;
    char s[10];

    itob(n, s, 2);
    printf("%d => %s\n", n, s);
}