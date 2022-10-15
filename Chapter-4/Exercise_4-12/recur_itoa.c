#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>

void itoa(int n, char s[]);

int main(void) {
    char buffer[20];

    printf("INT_MIN: %d\n", INT_MIN);
    itoa(INT_MIN, buffer);
    printf("Buffer : %s\n", buffer);
    
    return 0;
}

void itoa(int n, char d[])
{
    static int i=0;

    if (n < 0 && d[0] != '-')
        d[i++] = '-';

    if (n/10 != 0)
    {
        itoa(n / 10, d);
    }

    if (n < 0)
        d[i++] = (-(n % 10) + '0');
    else
        d[i++] = (n % 10 + '0');
    
    d[i] = '\0';
}

