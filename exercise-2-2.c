/********************************************************************
Write a loop equivalent to the for loop above without using && or ||.
********************************************************************/

#include <stdio.h>

int main()
{
    int i = 0;

    while ((c=getchar()) != EOF) {
        if (i >= lim-1)
            break;
        if (c == '\n')
            break;
        s[i] = c;
        ++i;
    }

    return 0;
}