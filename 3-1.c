#include <stdio.h>

int binsearch(int x, int v[], int n);
int binsearch_fast(int x, int v[], int n);

int main()
{
    int n, x;
    n = 1000000000;
    x = 3;
    int v[n];
    for (int i = 0; i < n; i++)
    {
        v[i] = i + 1;
    }
    // printf("%d\n", binsearch(x, v, n));
    printf("%d\n", binsearch_fast(x, v, n));
    return 0;
}

int binsearch_fast(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high)
    {
        if (x == v[mid])
        {
            return mid;
        }
        mid = (low + high) / 2;
        if (x < v[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return (x == v[mid]) ? mid : -1;
}

int binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (x < v[mid])
        {
            high = mid - 1;
        }
        else if (x > v[mid])
        {
            low = mid + 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}