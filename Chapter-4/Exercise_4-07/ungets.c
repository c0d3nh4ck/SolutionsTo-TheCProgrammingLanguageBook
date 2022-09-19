#include <stdio.h>
#include <string.h>

#define BUFSIZE 10

char buf[BUFSIZE];
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

void ungets(char *s)
{
    int i, len;
    len = strlen(s);
    if (BUFSIZE - bufp >= len)
    {
        for (i = strlen(s) - 1; i >= 0; i--)
            ungetch(s[i]);
    }
    else
        printf("error: insufficient space in buffer, can't execute ungets()\n");
}

int main()
{
    char s[] = "Rapa chika paka, raja babu\n";
    int c;
    ungets(s);
    while ((c = getch()) != EOF)
        putchar(c);
    return 0;
}
