#include <stdio.h>
#define MAXLINE 80

int get_line(char s[]);
void reverse(char s[], int l);

int main()
{
    int len;
    char line[MAXLINE];

    len = get_line(line);
    reverse(line, len);

    return 0;
}

int get_line(char s[])
{
    int c, i;

    for (i = 0; (c=getchar()) != EOF && c != '\n'; i++)
        s[i] = c;
    s[i] = '\0';

    return i;
}

void reverse(char s[], int len)
{
    int i, j;
    char ns[len];

    j = 0;
    for (i = len-1; i >= 0; i--)
    {
        ns[j] = s[i];
        j++;
    }
    ns[j] = '\0';

    printf("%s\n", ns);
}