/*******************************************************************************
Exercuse 2-5: Write the function any(s1, s2), which return the first location in
the string s1 where any character from the string s2 occurs, or -1 if s1
contains no characters from s2. (The standard library function strpbrk) does the
same job but returns a pointer to the location.)
*******************************************************************************/

#include <stdio.h>

int any(char s1[], char s2[])
{
    int i, j;

    for (i = 0; s2[i] != '\0'; i++)
        for (j = 0; s1[j] != '\0'; j++)
            if (s1[j] == s2[i])
                return j;

    return -1;
}

int main()
{
    int i;
    char s1[] = "pikachu";
    char s2[] = "charizard";

    i = any(s1, s2);

    if (i != -1)
        printf("Found char on position: %d, starting with 0 of course.\n", i);
    else
        printf("Zannen, didn't find a match.\n");
}