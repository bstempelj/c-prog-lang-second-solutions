/*******************************************************************************
Exercise 2-6: Write a function setbits(x,p,n,y) that returns x with the n bits
that begin at position p set to the rightmost n bits of y, leaving the other
bits unchanged.
*******************************************************************************/

#include <stdio.h>

unsigned setbits(unisgned x, int p, int n, unsigned y)
{
  return x | ((y & ~(~0 << n)) << p);
}

int main()
{
  unsigned int x = 0x756;
  unsigned int y = 0x5d7;

  printf("x: %d\ny: %d\n", x, y);
  printf("setbits: %d\n", setbits(x, 4, 3, y));

  return 0;
}