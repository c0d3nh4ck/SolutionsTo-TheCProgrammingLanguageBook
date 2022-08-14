#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>

void itob(long int n, char s[], int b);
void reverse(char s[]);

int main(void) {
    char buffer[36];
    int b;
    long int n;

    printf("Enter number to convert: ");
    scanf("%ld", &n);
    
    printf("Enter base for conversion: ");
    scanf("%d", &b);

    
    itob(n, buffer, b);
    printf("Buffer (base '%d') : %s\n", b, buffer);
    
    return 0;
}

void itob(long int n, char s[], int b) {
    int i; 
    long int sign;
    
    sign = n;
    
    char digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    if (b < 2 || b > 36)
    {
        fprintf(stderr, "Cannot support base %d\n", b);
        exit(EXIT_FAILURE);
    }
    
    i = 0;
    do {
        s[i++] = digits[abs(n % b)];
    } while ( n /= b );
    
    if (sign < 0)
        s[i++] = '-';
    
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
