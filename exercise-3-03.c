/*******************************************************************************
Exercise 3-3: Write a function expand(s1,s2) that expands shorthand notations
like a-z in the string s1 into the equivalent complete list abc..xyz in s2.
Allow for letters of either case and digits, and be prepared to handle cases
like a-b-c and a-z0-9 and -a-z. Arrange that a leading or trailing - is taken
literally.
*******************************************************************************/

#include <stdio.h>
#include <ctype.h>

void expand(char s1[], char s2[])
{
    int i, j, neg;
    char c;

    i = neg = (s1[0] == '-') ? 1 : 0;
    j = 0;
    while (s1[i] != '\0')
    {
        if (s1[i] == '-' && isalnum(s1[i+1]))
        {
            if (neg)
            {
                c = s1[i+1];
                while (c >= s1[i-1])
                    s2[j++] = c--;
            }
            else
            {
                c = s1[i-1];
                while (c <= s1[i+1])
                    s2[j++] = c++;
            }
            i++;
        }
        i++;
    }
    s2[j] = '\0';
}

int main()
{
    char s1[] = "a-b-c";
    char s2[100];

    expand(s1, s2);
    printf("%s\n", s2);
}