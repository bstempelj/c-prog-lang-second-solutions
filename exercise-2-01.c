/*******************************************************************************
Write a program to determine the ranges of char, short, int, and long variables,
both signed and unsigned, by printing appropriate values from standard headers
and by direct computation. Harder if you compute them: determine the ranges of
various floating-point types.
*******************************************************************************/

#include <stdio.h>
#include <limits.h>

int main()
{
    printf("char bit: %d\n", CHAR_BIT);

    printf("signed char min: %d\n", SCHAR_MIN);
    printf("signed char max: %d\n", SCHAR_MAX);
    printf("unsigned char max: %d\n", UCHAR_MAX);

    printf("char min: %d\n", CHAR_MIN);
    printf("char max: %d\n", CHAR_MAX);

    printf("short min: %d\n", SHRT_MIN);
    printf("short max: %d\n", SHRT_MAX);
    printf("unsigned short max: %d\n", USHRT_MAX);

    printf("int min: %d\n", INT_MIN);
    printf("int max: %d\n", INT_MAX);
    printf("unsigned int max: %d\n", UINT_MAX);

    printf("long min: %lu\n", LONG_MIN);
    printf("long max: %lu\n", LONG_MAX);
    printf("unsigned long max: %lu\n", ULONG_MAX);
    return 0;
}