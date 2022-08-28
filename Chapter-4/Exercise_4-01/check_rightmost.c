#include <stdio.h>
#define MAXLEN 100

int strindex(char source[], char searchfor[]);
int get_line(char line[], int max);

char pattern[] = "are";

int main()
{
    char line[MAXLEN];
    int found = 0;
    int idx;

    while (get_line(line, MAXLEN) > 0)
    {
        if ((idx = strindex(line, pattern)) >= 0)
        {
            printf("at index: %d\n", idx);
            found++;
        }
    }
    return found;
}

int get_line(char s[], int lim)
{
    int c, i;

    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c!='\n')
    {
        s[i++] = c;
    }

    if (c == '\n')
        s[i++] = c;

    s[i] = '\0';
    return i;
}

int strindex(char s[], char t[])
{
    int i, j, k;
    int idx = -1;

    for (i=0; s[i] != '\0'; i++)
    {
        for (j=i, k=0; t[k] != '\0' && s[j] == t[k]; j++, k++) 
        {
            ;
        }
        if (k > 0 && t[k] == '\0')
        {
            idx = i;
        }
    }
    return idx;
}
    
