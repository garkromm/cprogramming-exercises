#include <stdio.h>

char lower(char c);
int main()
{
    char c = 'C';
    printf("%c", lower(c));

    return 0;
}

char lower(char c)
{
    return c >= 'A' && c <= 'Z' ? c + 'a' - 'A' : c;
}