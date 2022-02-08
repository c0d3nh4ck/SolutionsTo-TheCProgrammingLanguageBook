#include <stdio.h>

int main()
{
    int c, v;
    
    while((c = getchar()) != EOF)
    {
        if (c != ' ' || v != ' ')
        {
            putchar(c);
            v = c;
        }
    }

    return 0;
}

