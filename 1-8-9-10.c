#include <stdio.h>

void main()
{
    printf("%d", '\\');
    printf("%c", 92);
    int c, n1;

    n1 = 0;
    while ((c = getchar()) != EOF)
    {

        if (c == '\n' || c == '\b' || c == '\t' || c == ' ')
        {

            putchar('\\');
            putchar(c == '\n' ? '\n' : c == '\b' ? 'b'
                                   : c == '\t'   ? 't'
                                   : c == ' '    ? ' '
                                                 : c);
            putchar('\n');
            ++n1;
        }
        printf("%d\n", n1);
        if (c == ' ')
        {
            putchar(' ');
            while ((c = getchar()) == ' ')
            {
                ;
            }
        }
    }
}