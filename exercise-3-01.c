/*******************************************************************************
Exercise 3-1: Our binary search makes two tests inside the loop, when one would
suffice (at the price of more tests outside). Write a version with only one test
inside the loop and measure the difference in run-time.
*******************************************************************************/

#include <stdio.h>

int mybinsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low < high)
    {
        mid = (low+high) / 2;
        if (x <= v[mid])
            high = mid;
        else
            low = mid + 1;
    }

    if (x == v[low])
        return low;

    return -1;
}

int main()
{
    int i;
    int v[10];

    for (i = 0; i < 10; i++)
        v[i] = i;

    printf("%d\n", mybinsearch(2, v, 10));
}