#include <stdio.h>

void squeeze(char s1[], char s2[]);
int any(const char s1[], const char s2[]);

int main()
{
    char s1[] = "remove every e and r from me";
    char s2[] = "re";

    printf("%s\n", s1);
    squeeze(s1, s2);
    printf("%s\n", s1);

    printf("%d\n", any(s1, "f"));
    return 0;
}

void squeeze(char s1[], char s2[])
{
    int i = 0;
    int j = 0;
    int l = 0;
    int dup = 0;
    while (s1[i] != '\0')
    {
        dup = 0;
        j = 0;
        while (s2[j] != '\0')
        {
            if (s1[i] == s2[j++])
            {
                dup = 1;
                break;
            }
        }
        if (!dup)
        {
            s1[l++] = s1[i++];
        }
        else
        {
            s1[i++] = '\0';
        }
    }
    s1[i] = '\0';
}

int any(const char s1[], const char s2[])
{
    int i = 0;
    int j = 0;
    while (s1[i] != '\0')
    {
        j = 0;
        while (s2[j] != '\0')
        {
            if (s1[i] == s2[j++])
            {
                return i;
            }
        }
        i++;
    }
    return -1;
}
