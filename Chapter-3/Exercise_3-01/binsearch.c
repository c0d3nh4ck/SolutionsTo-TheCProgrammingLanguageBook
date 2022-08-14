#include <stdio.h>

int binsearch(int x, int v[], int n)
{
    int low, mid, high;

    low = 0;
    high = n-1;

    while (low <= high)
    {
        mid = (low+high)/2;

        if (x <= v[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    if (x == v[low])
        return low;
    else
        return -1;
}

int main()
{
    int v[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int n = sizeof(v)/sizeof(v[0]);

    int inp;
    printf("Input a number : ");
    scanf("%d", &inp);

    int pos = binsearch(inp, v, n);

    printf("\nThis is the position: %d\n", pos);

    return 0;
}

