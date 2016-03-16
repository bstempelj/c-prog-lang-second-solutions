/*******************************************************************************
Exercise 4-2: Extend atof to handle scientific notation of the form 123.45e-6
where a floating-point number may be followed by e or E and an optionally
signed exponent.
*******************************************************************************/

#include <stdio.h>
#include <math.h>
#define MAXLINE 100

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

double atof(char s[])
{
    double val, power, e;
    int i, sign, esign;

    for (i = 0; isspace(s[i]); i++)
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    if (s[i] == 'e' || s[i] == 'E')
    {
        esign = (s[i+1] == '-') ? -1 : 1;
        i += (esign == -1) ? 2 : 1;
        for (e = 0.0; isdigit(s[i]); i++)
            e = 10.0 * e + (s[i] - '0');
        return (sign * val / power) * pow(10, esign*e);
    }
    return sign * val / power;
}

int main()
{
    double n;
    char s[] = "123.45e-6";

    n = atof(s);
    printf("%.10f\n", n);
}