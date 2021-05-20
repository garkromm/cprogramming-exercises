#include <stdio.h>

#define TABSIZE 4
#define MAXLINE 1000

int get_line(char s[], int lim);
void detab(char s[], char t[]);
void entab(char s[], char t[]);

int main()
{
    int len;
    char s[MAXLINE];
    char t[MAXLINE * TABSIZE];
    char et[MAXLINE];

    while (get_line(s, MAXLINE))
    {
        detab(s, t);
        printf("%s", t);
        entab(t, et);
        printf("%s", et);
    }
}

int get_line(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    {
        s[i] = c;
    }
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void detab(char s[], char t[])
{
    int i = 0;
    int j = 0;
    int blanks;
    char c;
    while ((c = s[i]) != '\0')
    {
        if (c != '\t')
        {
            t[j] = c;
            j++;
        }
        else
        {
            blanks = TABSIZE - j % TABSIZE;
            while (blanks > 0)
            {
                t[j] = ' ';
                j++;
                blanks--;
            }
        }
        i++;
    }
    t[j] = '\0';
}

void entab(char s[], char t[])
{
    int i = 0;
    int j = 0;
    int blanks = 0;
    char c;
    while ((c = s[i]) != '\0')
    {
        if (c != ' ')
        {
            t[j] = c;
            j++;
        }
        else
        {
            blanks++;
            if (blanks == TABSIZE)
            {
                t[j] = '\t';
                j++;
                blanks = 0;
            }
        }
        i++;
    }
    t[j] = '\0';
}