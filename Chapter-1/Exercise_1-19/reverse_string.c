#include <stdio.h>

#define MAXLEN 1000
#define MAXLINES 100

int get_line(char [], int);
void reverse_and_copy(char [], char [], int);

int main()
{
    int len, numLines;
    char line[MAXLEN];
    char lines[MAXLINES][MAXLEN];

    numLines = 0;

    while ((len = get_line(line, MAXLEN)) > 0)
    {
        reverse_and_copy(lines[numLines++], line, len);
    }

    for (int i=0; i < numLines; i++)
    {
        printf("%d. %s", i+1, lines[i]);
    }
    
    return 0;
}

int get_line(char s[], int limit)
{
    int c, i;
    for (i=0; i< limit-1 && (c=getchar())!=EOF && c != '\n'; i++)
        s[i] = c;

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

void reverse_and_copy(char to[], char from[], int len)
{
    int i = 0;
    for (int j=len-2; j>=0; --j)
    {
        to[i++] = from[j];
    }
    to[i] = '\n';
}

