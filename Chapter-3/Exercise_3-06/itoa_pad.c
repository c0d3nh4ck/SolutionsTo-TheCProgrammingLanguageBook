#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void itoa(int n, char s[], int width);
void reverse(char s[]);

int main(void) {
    char buffer[36];
    int width, n; 

    printf("Enter a number: ");
    scanf("%d", &n);

    printf("Enter width value: ");
    scanf("%d", &width);
    
    itoa(n, buffer, width);
    printf("%s\n", buffer);
    
    return 0;
}

void itoa(int n, char s[], int width) {
    int i, sign;
    sign = n;
    
    i = 0;
    do {
        s[i++] = abs(n % 10) + '0';
    } while ( n /= 10 );
    if (sign < 0)
        s[i++] = '-';

    while (width > i-1)
    {
        s[i++] = ' ';
        width--;
    }

    s[i] = '\0';

    reverse(s);
}

void reverse(char s[]) {
    int c, i, j;
    for ( i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
