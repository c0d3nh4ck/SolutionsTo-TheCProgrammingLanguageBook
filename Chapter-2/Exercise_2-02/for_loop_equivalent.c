#include <stdio.h>

#define MAXLEN 100

int get_line(char s[], int limit)
{
    int c, i;
    for (i=0; i < limit-1; i++)
    {
        if ((c=getchar())==EOF) break;

        else if (c == '\n') break;

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

int main()
{
    int len;
    char line[MAXLEN];

    for(int i=0; (len = get_line(line, MAXLEN)) > 0; i++)
    {
        printf("\n%d. %s\n", i+1, line);
    }

    return 0;
}
