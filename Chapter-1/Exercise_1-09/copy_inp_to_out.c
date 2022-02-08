#include <stdio.h>

int main()
{
    int c;
    
    while((c = getchar()) != EOF)
    {
        if (c == ' ')
        {
            putchar(c);
            while ((c = getchar()) == ' ')
                ;

            if (c == EOF) break;
        }
        putchar(c);
    }

    return 0;
}

