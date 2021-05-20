#include <stdio.h>

#define MAXLINE 1000
#define ON 1
#define OFF 0

int get_multi_line(char s[], int lim);
int check_next_char(int i, char s[], char check[]);
void remove_comments(char s[], char t[]);

int main()
{
    int len;
    char s[MAXLINE];
    char t[MAXLINE];

    while (get_multi_line(s, MAXLINE))
    {
        remove_comments(s, t);
        printf("%s", t);
    }
}

int get_multi_line(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
    {
        s[i] = c;
    }
    if (c == '\n')
    {
        s[i] = c;
        i++;
    }
    s[i] = '\0';
    return i;
}

void remove_comments(char s[], char t[])
{
    int i = 0;
    int j = 0;
    int multi = OFF;
    int single = OFF;
    int comment = OFF;
    char c;
    char single_start[3] = {'/', '/', '\0'};
    char multi_start[3] = {'/', '*', '\0'};
    char single_end[2] = {'\n', '\0'};
    char multi_end[3] = {'*', '/', '\0'};

    while ((c = s[i]) != '\0')
    {

        if (comment == ON)
        {
            //is this the := origin
            if (single = check_next_char(i, s, single_end))
            {
                comment = OFF;
                i += single;
            }
            else if (multi = check_next_char(i, s, multi_end))
            {
                comment = OFF;
                i += multi;
            }
        }
        else
        {
            if ((single = check_next_char(i, s, single_start)) || (multi = check_next_char(i, s, multi_start)))
            {
                comment = ON;
                i++;
            }
            else
            {
                t[j] = c;
                j++;
            }
        }
        i++;
    }
    t[j] = '\0';
}

// is this even good ?
int check_next_char(int i, char s[], char check[])
{
    int j = 0;
    while (check[j] != '\0')
    {
        if (s[i + j] != check[j])
        {
            return 0;
        }
        else
        {
            j++;
        }
    }
    return j - 1;
}