
#include <stdio.h>

unsigned setbits(unsigned x, unsigned y, int p, int n);
void binprintf(int v);

int main()
{
    //1 1
    //2 01
    //3 11
    //4 001
    //5 101
    //6 011
    unsigned a = 1;
    binprintf(a);

    unsigned b = 2;
    binprintf(b);

    printf("a: %d, b: %d\n", a, b);
    b = setbits(a, b, 8, 4);
    printf("a: %d, b: %d\n", a, b);

    return 0;
}

unsigned setbits(unsigned x, unsigned y, int p, int n)
{
    //shift 1's p to right;
    //shift 1's (p-n) to right
    // or both to get 0 in p -> n range
    unsigned mask_x = ((~0 << p) | ~(~0 << (p - n)));
    x = x & mask_x;

    //shift 1's rifht n times and turn all to 0's
    unsigned mask_y = ~(~0 << n);
    y = y & mask_y;

    return (x | y);
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
