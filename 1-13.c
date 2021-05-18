#include <stdio.h>

#define WORDLIMIT 30

void main()
{
    int word_len_arr[WORDLIMIT + 1];
    int c;
    int word_len = 0;
    int max = 0;
    for (int i = 0; i < WORDLIMIT + 1; i++)
    {
        word_len_arr[i] = 0;
    }
    while ((c = getchar()) != EOF)
    {

        if (c == ' ' || c == '\t' || c == '\n')
        {
            word_len_arr[word_len]++;
            if (word_len_arr[word_len] > max)
            {
                max = word_len_arr[word_len];
                if (max > WORDLIMIT)
                {
                    break;
                }
            }
            word_len = 0;
            if (c == '\n')
            {
                break;
            }
            continue;
        }
        word_len++;
    }
    for (int i = max; i > 0; i--)
    {
        printf("%3d  |", i);
        for (int j = 1; j <= WORDLIMIT; j++)
        {
            if (word_len_arr[j] >= i)
            {
                printf("|##|");
            }
            else
            {
                printf("|  |");
            }
        }
        printf("\n");
    }
    printf("count ");
    for (int i = 1; i <= WORDLIMIT; i++)
    {
        if (i < 10)
        {
            printf("|%d |", i);
        }
        else
        {
            printf("|%d|", i);
        }
    }
    printf("\n");
    printf("freq  ");
    for (int i = 1; i <= WORDLIMIT; i++)
    {
        printf("|%d |", word_len_arr[i]);
    }
    printf("\n");
}
