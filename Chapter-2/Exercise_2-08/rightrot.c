#include <stdio.h>

unsigned rightrot(unsigned, int);

int main()
{
    unsigned int bits;
    bits =  rightrot((unsigned) 63, 3);

    printf("%u\n", bits);
    return 0;
}

unsigned rightrot(unsigned x, int n)
{
    return (x >> n) | ((x & (~(~0 << n))) << (8 - n));
}
