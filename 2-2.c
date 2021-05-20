#include <stdio.h>

int main()
{

    const int max = 100;
    int i = 0;
    int lim = max;
    int c;
    char s[max];

    while (i < lim - 1)
    {
        if ((c = getchar()) != '\n')
        {
            if (c != EOF)
            {
                s[i] = c;
                i++;
            }
        }
        else
        {
            s[i] = c;
            s[i + 1] = '\0';
            break;
        }
    }
    printf("%s", s);
    return 0;
}
