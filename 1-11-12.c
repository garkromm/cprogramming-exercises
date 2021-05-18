#include <stdio.h>

#define AND &&
#define OR ||
// and we have python :D
#define EQ ==
#define NOT !=
// only here !

// 11
// no new lines
// no words

void main()
{
    int c;
    while ((c = getchar()) NOT EOF)
    {
        putchar(c);
        if (c EQ ' ' OR c EQ '\n' OR c EQ '\t')
        {
            putchar('\n');
        }
    }
}