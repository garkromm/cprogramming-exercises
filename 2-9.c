#include <stdio.h>

int bitcount(unsigned x);
int bitcount_fast(unsigned x);

int main()
{
    unsigned x = 3;
    printf("%d\n", bitcount(x));
    printf("%d\n", bitcount_fast(x));
    return 0;
}

int bitcount_fast(unsigned x)
{
    if (x == 0)
    {
        return 0;
    }
    int b = 1;

    while (x = (x &= (x - 1)))
    {
        b++;
    }
    return b;
}

int bitcount(unsigned x)
{
    int b;

    for (b = 0; x != 0; x >>= 1)
    {
        if (x & 01)
        {
            b++;
        }
    }
    return b;
}