#include <stdio.h>

#define MAXLEN 1000

int get_line(char [], int);
void copy(char [], char []);

int main()
{
    int len, max;
    char line[MAXLEN];
    char longest[MAXLEN];

    max = 0;
    
    while ((len = get_line(line, MAXLEN)) > 0)
    {
        printf("\nLength of line \n\"\"\"\n%s\"\"\"\n => %d\n\n", line, len);

        if (len > max)
        {
            max = len;
            copy(longest,  line);
        }
    }
    
    if (max > 0) 
    {
        printf("\n\nLongest line is \n\"\"\"\n%s\"\"\"\n", longest);

        if (max > MAXLEN) printf("\nLength limit exceeded");
        printf("\nIt's length is %d\n", max);
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

void copy(char to[], char from[])
{
    for (int i=0; (to[i] = from[i]) != '\0'; ++i) ;
}

