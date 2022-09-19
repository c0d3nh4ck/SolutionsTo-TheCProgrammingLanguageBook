#include <stdio.h>
#define BUFSIZE 100

int buf[BUFSIZE];   // changed 'char' type to 'int' so that it can handle EOF
                    // as value of EOF is -1 and can be stored in 'int' type not 'char'
int bufp = 0;

int getch(void)
{
    return bufp > 0 ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("error: stack is full, can't execute ungetch()\n");
    else
        buf[bufp++] = c;
}
