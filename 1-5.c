#include <stdio.h>

void main()
{
    int celsius;
    printf("=C==|==F===\n");
    for (celsius = 100; celsius >= -100; celsius -= 10)
    {
        printf("%3.1d %3.1f\n", celsius, (celsius * (9.0 / 5.0) + 32));
    }
}
