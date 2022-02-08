#include <stdio.h>

#define IN 1    // state when inside a word
#define OUT 0   // state when outside a word

int main()
{
    int c, state;

    state = OUT;
    
    while ((c = getchar()) != EOF)
    {
        if (c != '\n' && c != ' ' && c != '\t')
        {
            state = IN;
            putchar(c);
        }
        else if (state == IN)
        {
            state = OUT;
            putchar('\n');
        }
    }
}
