#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

int htoi(const char s[]);

int main()
{
    // htoi("0x2A");
    printf("%d\n", htoi("0x2A"));
    printf("%d\n", htoi("0x29A"));
    return 0;
}

int htoi(const char s[])
{
    if (s[0] != '0' && s[1] != 'x')
    {
        return -1;
    }
    long double r = 0;
    int digit;
    char lower;
    int len = strlen(s) - 3;
    int i = 2;
    while ((lower = tolower(s[i])) != '\0')
    {

        if (lower >= '0' && lower <= '9')
        {
            digit = lower - '0';
        }
        else if (lower >= 'a' && lower <= 'f')
        {
            digit = lower - 'a' + 10;
        }
        else
        {
            return -1;
        }
        r += pow(16, len--) * digit;
        i++;
    }
    return (int)r;
}