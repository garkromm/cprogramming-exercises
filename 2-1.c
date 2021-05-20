#include <stdio.h>
#include <limits.h>

int main()
{
    printf("char --> Max: %d  Min: %d\n", CHAR_MAX, CHAR_MIN);
    printf("int --> Max: %d  Min: %d\n", INT_MAX, INT_MIN);
    printf("long --> Max: %ld  Min: %ld\n", LONG_MAX, LONG_MIN);
    printf("long long --> Max: %lld  Min: %lld\n", LLONG_MAX, LLONG_MIN);
    printf("short --> Max: %d  Min: %d\n", SHRT_MAX, SHRT_MIN);
    printf("signed char --> Max: %d  Min: %d\n", SCHAR_MAX, SCHAR_MIN);
    printf("uchar --> Max: %u  Min: %d\n", UCHAR_MAX, 0);
    printf("uint --> Max: %ui  Min: %d\n", UINT_MAX, 0);
    printf("ull --> Max: %lu Min: %d\n", ULLONG_MAX, 0);
    printf("ul --> Max: %u  Min: %d\n", ULONG_MAX, 0);
    printf("us --> Max: %u  Min: %d\n", USHRT_MAX, 0);

    return 0;
}
