#include <stdio.h>
#define MAXSIZE 1000

int get_line(char line[]);

int main()
{
    int len;
    char line[MAXSIZE];

    while ((len = get_line(line)) > 0)
        if (len > 80)
            printf(">>> %s\n", line);

    return 0;
}

int get_line(char line[])
{
    int c, i;

    i = 0;
    while ((c = getchar()) != EOF && c != '\n')
    {
        line[i] = c;
        i++;
    }
    line[i] = '\0';

    return i;
}