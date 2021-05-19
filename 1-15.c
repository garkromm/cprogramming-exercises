#include <stdio.h>

int cel_to_fahr(float celsius);

int main()
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
        fahr = cel_to_fahr(celsius);
        printf("%6.1f %3.0f\n", celsius, fahr);
        celsius += step;
    }

    return 0;
}

int cel_to_fahr(float celsius)
{
    return celsius * (9.0 / 5.0) + 32;
}