
#include <stdio.h>

unsigned invert(unsigned x, int p, int n);
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

    unsigned b = 0;

    printf("a: %d, b: %d\n", a, b);
    b = invert(a, 5, 0);
    printf("a: %d, b: %d\n", a, b);

    return 0;
}

unsigned invert(unsigned x, int p, int n)
{
    unsigned shift_n_r = ~(~0 << n);
    unsigned shift_n_p_r = shift_n_r << p;
    //reverse 1's
    unsigned mask_x1 = (x & ~(shift_n_p_r));
    //reverse 0's
    unsigned mask_x2 = (shift_n_r & ~(x & shift_n_p_r));

    return (mask_x1 | mask_x2);
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
