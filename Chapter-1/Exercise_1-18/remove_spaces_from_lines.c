#include <stdio.h>

#define MAXLEN 1000
#define MAXLINES 100

int get_line(char [], int);
void copy(char [], char []);

int main()
{
    int len, numLines;
    char line[MAXLEN];
    char lines[MAXLINES][MAXLEN];

    numLines = 0;
    
    while ((len = get_line(line, MAXLEN)) > 0)
    {
        copy(lines[numLines++], line);
    }

    for (int i=0; i < numLines; i++)
    {
        printf("%d. %s", i+1, lines[i]);
    }
    
    return 0;
}

int get_line(char s[], int limit)
{
    int c, i, v, w;
    for (i=0; i< limit-1 && (c=getchar())!=EOF && c != '\n'; i++)
    {
        if ((c != ' ' || v != ' ') && (v != '\t' || c != '\t') && (v != ' ' || c != '\t') && (v != '\t' || c != ' '))
        {
            v = c;
            if (c == '\t') 
            {
                c = ' ';
            }

            s[i] = c;
        }
        else 
        {
            --i;
        }
    }


    if (i == (limit - 1))
    {
        while((c=getchar())!='\n') ++i;
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
    for (int i=0; (to[i] = from[i]) != '\0'; ++i) ;
}

