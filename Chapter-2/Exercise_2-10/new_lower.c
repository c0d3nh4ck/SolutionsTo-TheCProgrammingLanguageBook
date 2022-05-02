#include <stdio.h>

char lower(char);

int main()
{
    char x;
    printf("Input : ");
    scanf("%c", &x);
    
    printf("To lower : %c\n", lower(x));

    return 0;
}

char lower(char x)
{
    return (x >= 'A' && x <= 'Z' ? x = x + 'a' - 'A' : x);
}

