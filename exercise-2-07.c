/*******************************************************************************
Exercise 2-7: Write a function invert(x,p,n) that returns x with the n bits that
begin at position p inverted (i.e., 1 changed to 0 and vice versa), leaving the
others unchanged.
*******************************************************************************/

#include <stdio.h>

unsigned invert(unsigned x, int p, int n)
{
  return x ^ (~(~0 << n) << p);
}

int main()
{
  unsigned int x = 0x756;

  printf("x: %d\n", x);
  printf("invert: %d\n", invert(x, 4, 3));

  return 0;
}