/*******************************************************************************
Exercise 3-2: Write a function escape(s,t) that converts characters like newline
and tab into visible escape sequences like \n and \t as it copies the string t
to s. Use a switch. Write a function for the other direction as well, converting
escape sequences into real characters.
*******************************************************************************/

#include <stdio.h>

void escape(char s[], char t[])
{
    int i, j;

    for (i = j = 0; s[i] != '\0'; i++)
    {
        switch (s[i])
        {
            case '\n':
                t[j++] = '\\';
                t[j++] = 'n';
                break;
            case '\t':
                t[j++] = '\\';
                t[j++] = 't';
                break;
            default:
                t[j++] = s[i];
        }
    }
    t[j] = '\0';
}

void noescape(char s[], char t[])
{
    int i, j;

    for (i = j = 0; s[i] != '\0'; i++)
    {
        if (s[i] == '\\')
        {
            switch (s[i++])
            {
                case 'n':
                    t[j++] = '\n';
                    break;
                case 't':
                    t[j++] = '\t';
                    break;
            }
        }
        else
        {
            t[j++] = s[i];
        }
    }
    t[j] = '\0';
}

int main()
{
    char t[100], u[100];
    char s[] = "Ohayou\nKonnichiha\tKonbanwa";

    escape(s, t);
    printf("%s\n", t);
    noescape(t, u);
    printf("%s\n", u);

    return 0;
}