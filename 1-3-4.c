#include <stdio.h>

void main()
{
    float celsius, fahr;
    int lower, upper, step;

    lower = -100;
    upper = 100;
    step = 10;

    celsius = lower;
    printf("===C==|==F===\n");
    while (celsius <= upper)
    {
        fahr = celsius * (9.0 / 5.0) + 32;
        printf("%6.1f %3.0f\n", celsius, fahr);
        celsius += step;
    }
}
