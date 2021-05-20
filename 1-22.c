#include <stdio.h>

#define FOLDSIZE 10
#define MAXLINE 1000
#define ON 1
#define OFF 0

int get_line(char s[], int lim);
void fold(char s[], char t[]);

int main()
{
    int len;
    char s[MAXLINE];
    char t[MAXLINE];

    while (get_line(s, MAXLINE))
    {
        fold(s, t);
        printf("%s", t);
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

void fold(char s[], char t[])
{
    int i = 0;
    int j = 0;
    int blank = OFF;
    int count = 0;
    char c;
    while ((c = s[i]) != '\0')
    {
        if (count < FOLDSIZE)
        {
            //is this insane ?!?
            if ((c == ' ' || c == '\t'))
            {
                if (blank == ON)
                {
                    i++;
                    continue;
                }
                else
                {
                    blank = ON;
                }
            }
            //
            blank = OFF;
            t[j] = c;
            count++;
            i++;
            j++;
        }
        else
        {
            count = 0;
            t[j] = '\n';
            j++;
            t[j] = c;
            i++;
        }
    }
    t[j] = '\0';
}