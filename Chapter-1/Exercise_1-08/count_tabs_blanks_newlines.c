#include <stdio.h>

int main()
{
    int blank = 0; 
    int tab = 0; 
    int nl = 0;

    int c;

    while ((c =getchar()) != EOF)
    {
        switch(c)
        {
            case ' ':
                blank++;
                break;
            case '\t':
                tab++;
                break;
            case '\n':
                nl++;
                break;
            default:
                break;
        }
    }

    printf("Number of blanks = %d\n", blank);
    printf("Number of tabs = %d\n", tab);
    printf("Number of newlines = %d\n", nl);

    return 0;
}
        
