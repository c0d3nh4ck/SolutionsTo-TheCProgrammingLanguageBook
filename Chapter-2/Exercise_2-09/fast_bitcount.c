#include <stdio.h>

int bitcount(int);

int main()
{
    int b, inp;
    
    printf("Give the input :- \n");
    scanf("%d", &inp);

    b = bitcount(inp);
    printf("Number of 1s in %d is %d\n", inp, b);

    return 0;
}

int bitcount(int num)
{
    int count=0;
    
    while(num != 0)
    {
        num &= num - 1;
        count++;
    }

    return count;
}
