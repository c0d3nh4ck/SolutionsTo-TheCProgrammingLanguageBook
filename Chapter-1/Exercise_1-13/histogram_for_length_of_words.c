#include <stdio.h>

#define MAXLEN 10
#define IN 1    // state when inside a word
#define OUT 0   // state when outside a word

int main()
{
    int c, state, nlength[MAXLEN];

    int len=0;
    state = OUT;
    for (int i=0; i<MAXLEN; i++) nlength[i] = 0;
    
    while ((c = getchar()) != EOF)
    {
        if (c != '\n' && c != ' ' && c != '\t')
        {
            state = IN;
            len++;
        }
        else if (state == IN)
        {
            nlength[len-1]++;
            
            state = OUT;
            len = 0;
        }
    }

    for (int i=0; i<MAXLEN; i++)
    {
        printf("\n|%2d| ", i+1);
        for (int j=0; j<nlength[i]; j++)
        {
            putchar('*');
        }
    }
    printf("\n");
    
    return 0;
}
