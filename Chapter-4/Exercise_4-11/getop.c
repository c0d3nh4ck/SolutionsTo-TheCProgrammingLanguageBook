#include <stdio.h>
#include <ctype.h>
#include "calc.h"

int getop(char s[])
{
    int i, c;
    static char sbuf = EOF;

    if (sbuf == EOF || sbuf == ' ' || sbuf == '\t')
    {
        while ((s[0] = c = getch()) == ' ' || c == '\t')
            ;
        s[1] = '\0';
    }
    else
        c = sbuf;

    if (!isdigit(c) && c != '.')
        return c;
    i = 0;
    if (isdigit(c))
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')
        while (isdigit(s[++i] = c = getch()))
            ;

    s[i] = '\0';
    if (c != EOF)
        sbuf = c;

    return NUMBER;
}

