/*****************************************************************************
Exercise 2.6: Write a function setbits(x,p,n,y) that returns x with the n bits
that begin at position p set to the rightmost n bits of y, leaving the other
bits unchanged.
*****************************************************************************/

#include <stdio.h>

unsigned setbits(x, p, n, y)
{
    return (x >> (p+1-n) & ~0);
}

int main()
{
    int x = 0xAB;
    int y = 0xCE;

    printf("Result: %d\n", setbits(x, 2, 3, y));
}