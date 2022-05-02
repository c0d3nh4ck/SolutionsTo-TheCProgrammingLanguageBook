/* To understand this problem in a more better way, go through the link below :-
   https://www.learntosolveit.com/cprogramming/Ex_2.6_setbits.html
*/

#include <stdio.h>

unsigned setbits(unsigned, int, int, unsigned);

int main()
{

    unsigned int bits;
    bits = setbits((unsigned)22, 3, 2, (unsigned)40);

    printf("%u\n", bits);

    return 0;
}

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    return ((x & ~(~(~0 << n) << p+1-n)) | ((~(~0 << n) & y) << p+1-n));
}

