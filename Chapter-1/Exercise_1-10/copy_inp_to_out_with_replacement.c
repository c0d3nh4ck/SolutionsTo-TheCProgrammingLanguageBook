#include <stdio.h>

int main()
{
    int c, v;
    
    while((c = getchar()) != EOF)
    {
        switch(c)
        {
            case '\b':
                printf("\\b");
                break;
            case '\t':
                printf("\\t");
                break;
            case '\\':
                printf("\\\\");
                break;
            default:
                putchar(c);
                break;
        }
    }
    return 0;

    return 0;
}

