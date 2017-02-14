#include <stdio.h>
#define MAXLINE 80

int get_line(char line[]);
int get_bound(char line[], int len, int type);

int main()
{
    int i, j, len, start, end;
    char line[MAXLINE];
    char newline[MAXLINE];

    len = get_line(line);

    /* najdi prvo črko */
    start = get_bound(line, len, 0);
    /* najdi zadnjo črko */
    end = get_bound(line, len, 1);x<

    /* trim */
    j = 0;
    for (i = start; i <= end; i++)
    {
        newline[j] = line[i];
        j++;
    }
    newline[j] = '\0';

    printf("%s\n", newline);

    return 0;
}

int get_line(char line[])
{
    int c, i;

    for (i = 0; (c=getchar()) != EOF && c != '\n'; i++)
        line[i] = c;
    line[i] = '\0';

    return i;
}

int get_bound(char line[], int len, int type)
{
    int i;

    if (type == 0)
    {
        i = 0;
        while (line[i] == ' ' || line[i] == '\t')
            i++;
    }
    else if (type == 1)
    {
        i = len - 1;
        while (line[i] == ' ' || line[i] == '\t')
            i--;
    }

    return i;
}