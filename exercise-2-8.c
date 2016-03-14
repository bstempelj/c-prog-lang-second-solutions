/*******************************************************************************
Exercise: 2-8: Write a function rightrot(x,n) that returns the value of the
integer x rotated to the right by n bit positions.
*******************************************************************************/

#include <stdio.h>

// Work only with 8-bit numbers
unsigned rightrot(unsigned x, int n)
{
  return (x >> n) | ((x & ~(~0 << n)) << (8 - n));
}

int main()
{
  printf("rightrot: %d\n", rightrot(116, 3));
  return 0;
}