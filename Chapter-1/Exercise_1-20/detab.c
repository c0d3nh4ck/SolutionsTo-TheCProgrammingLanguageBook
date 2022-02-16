#include <stdio.h>

#define SPACE   ' '
#define TAB     '\t'
#define MAXBUF  1024


int main()
{
    int c;
    char buffer[MAXBUF];

    while((c = getchar()) != EOF)
    {
        if (c == TAB)
        {
            for (int j=0; j<4; j++)
            {
                putchar(' ');
            }
        }
        else putchar(c);
    }

    return 0;
}
