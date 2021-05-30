#include <stdio.h>

void binprintf(int v);
unsigned rightrot(unsigned x, unsigned n);

int main()
{
    unsigned a = 1;

    unsigned b = 0;

    printf("a: %d, b: %d\n", a, b);
    b = rightrot(a, 3);
    printf("a: %d, b: %d\n", a, b);
    return 0;
}

//https://en.wikipedia.org/wiki/Circular_shift
unsigned rightrot(unsigned x, unsigned n)
{
    return x << n | x >> (32 - n);
}

// stolen helper
void binprintf(int v)
{
    printf("int %5d --> ", v);
    unsigned int mask = 1 << ((sizeof(int) << 3) - 1);
    while (mask)
    {
        printf("%d", (v & mask ? 1 : 0));
        mask >>= 1;
    }
    printf("\n");
}
