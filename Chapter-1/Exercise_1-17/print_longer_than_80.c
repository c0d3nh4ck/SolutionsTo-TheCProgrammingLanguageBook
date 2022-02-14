#include <stdio.h>

#define MAXLEN 1000
#define MAXLINES 100
#define LONGERTHAN80 80

int get_line(char [], int);
void copy(char [], char []);

int main()
{
    int len, max;
    char line[MAXLEN];
    char moreThan80[MAXLINES][MAXLEN];

    max = 0;
    
    while ((len = get_line(line, MAXLEN)) > 0)
    {
        if (len > LONGERTHAN80) 
            copy(moreThan80[max++], line);
    }

    printf("\n\nLines whose length are more than 80 :- \n\n");
    for (int i=0; i < max; i++)
    {
        printf("%d. %s", i+1, moreThan80[i]);
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

