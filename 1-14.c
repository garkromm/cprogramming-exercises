#include <stdio.h>

#define MAXCHAR 256

void main()
{
    int word_len_arr[MAXCHAR] = {0};
    int c;
    int max = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == '\n')
        {
            break;
        }
        word_len_arr[c]++;
        if (word_len_arr[c] > max)
        {
            max = word_len_arr[c];
        }
    }
    for (int i = MAXCHAR; i > 0; i--)
    {
        if (word_len_arr[i] == 0)
        {
            continue;
        }
        printf("%c    |", i);
        for (int j = 0; j <= 10; j++)
        {
            if (word_len_arr[i] > j)
            {
                printf("|###|");
            }
            else
            {
                printf("|   |");
            }
        }
        printf("\n");
    }
    printf("\n");
    printf("count");
    for (int i = 0; i <= 10; i++)
    {
        printf("||>%d ", i);
    }
    printf("\n");
}
