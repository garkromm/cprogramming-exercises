#include <stdio.h>

#define MAXLINE 100

int get_line(char s[], int lim);
void copy(char to[], char from[]);
void reverse(char s[]);

int main()
{
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while ((len = get_line(line, MAXLINE)) > 0)
    {
        reverse(line);
        printf("reverse->");
        printf("%s\n", line);
        reverse(line);

        if (len > max)
        {
            max = len;
            copy(longest, line);
        }
        // 1-17
        if (len > 80)
        {
            printf(">80-> ");
            printf("%s", line);
        }
        if (max > 0)
        {
            printf("longest-> \n");
            printf("%s", longest);
        }
    }

    return 0;
}

int get_line(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    {
        // 1-18
        if ((c == ' ' || c == '\t') && (s[i - 1] == ' ' || s[i - 1] == '\t') && i != 0)
        {
            --i;
        }
        else
        {
            s[i] = c;
        }
    }
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
    {
        ++i;
    }
}

//1-19
void reverse(char s[])
{
    char temp;
    int length, i;
    length = 0;
    while (s[length] != '\0')
    {
        length++;
    }
    for (i = 0; i < length - 1; --length, i++)
    {
        temp = s[i];
        s[i] = s[length - 1];
        s[length - 1] = temp;
    }
}