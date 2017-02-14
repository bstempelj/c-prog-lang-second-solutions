/************************************************************************
Write the function htoi(s), which converts a string of hexadecimal digits
(including an optional 0x or 0X) into its equivalent integer value. The
allowable digits are 0 through 9, a through f, and A through F.
************************************************************************/

#include <stdio.h>
#include <ctype.h>

int isallowed(int c)
{
    if (isdigit(c))
        return 1;
    else if (c >= 'A' && c <= 'F')
        return 1;
    else if (c >= 'a' && c <= 'f')
        return 1;
    return 0;
}

int htoi(char s[])
{
    int i, n, c;

    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
        i = 2;
    else
        i = 0;

    n = 0;
    while (isallowed(s[i]))
    {
        if (s[i] != '0')
            n = 16 * n + (s[i] - '0' - 7);
        i++;
    }

    return n;
}

int main()
{
    char s[] = "0xFA";
    printf("%d\n", htoi(s));

    return 0;
}