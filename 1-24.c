#include <stdio.h>

#define MAXLINE 1000
#define ON 1
#define OFF 0

int get_multi_line(char s[], int lim);
int semi_invalid_c(const char *s);

int main()
{
    char s[MAXLINE];

    while (get_multi_line(s, MAXLINE))
    {
        printf("###invalid index %d\n", semi_invalid_c(s));
    }

    return 0;
}

int semi_invalid_c(const char *s)
{
    int i = 0;
    int j = -1;
    char t[MAXLINE] = {'\0'};

    while (*s != '\0')
    {
        if (*s == '[' || *s == '(' || *s == '{')
        {
            t[++j] = *s;
        }
        else if (*s == ']' || *s == ')' || *s == '}')
        {
            if (j == -1)
            {
                return i;
            }
            else if ((*s == ']' && t[j] == '[') || (*s == ')' && t[j] == '(') || (*s == '}' && t[j] == '{'))
            {
                t[j--] = '\0';
            }
            else
            {
                return i;
            }
        }
        i++;
        s++;
        printf("%s\n", t);
    }

    return -1;
}

int get_multi_line(char s[], int lim)
{
    int c, i;
    int new_line = OFF; /* double enter*/

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF; i++)
    {
        if (c == '\n')
        {
            if (new_line)
            {
                s[i] = '\0';
                break;
            }
            new_line = ON;
        }
        else
        {
            new_line = OFF;
        }
        s[i] = c;
    }

    return i;
}
