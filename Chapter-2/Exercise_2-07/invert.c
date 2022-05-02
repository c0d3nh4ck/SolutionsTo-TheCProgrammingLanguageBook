#include <stdio.h>

unsigned invert(unsigned, int, int);

int main()
{
    unsigned int bits;
    bits = invert((unsigned) 42, 4, 3);
    printf("%u\n", bits);

    return 0;
}

unsigned invert(unsigned x, int p, int n)
{
    return x ^ (~(~0 << n) << (p + 1 -n));
}
