#include <stdio.h>

void copy(char *dest, const char *src);

int main()
{

    char buf[128];
    char hello[] = "hallo, world!";
    hello[1] = 'e';
    copy(buf, hello);
    printf("%s\n", buf);
    printf("%s\n", hello);
    copy(buf, "hello, world!");
    printf("%s\n", buf);
    printf("%s\n", hello);

    return 0;
}

void copy(char *dest, const char *src)
{

    while ((*dest++ = *src++) != '\0')
    {
        printf("%p\n", &*src);
        printf("%c\n", *src);
        *src++ = '*';
        ;
    }
}
