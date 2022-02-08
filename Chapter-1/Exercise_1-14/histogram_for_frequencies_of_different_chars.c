#include <stdio.h>

#define FIRST_CHAR '!'
#define LAST_CHAR '~' 

int main()
{
    int NumOfChars = LAST_CHAR - FIRST_CHAR + 1;

    int c, charLength[NumOfChars];

    for (int i=0; i<NumOfChars; i++) charLength[i] = 0;

    while((c = getchar()) != EOF)
    {
        if (c >= '!' && c <= '~') charLength[c - '!']++;
    }

    for (int i=0; i<NumOfChars; i++)
    {
        printf("\n|%c|", '!'+i);
        for (int j=0; j<charLength[i]; j++) putchar('*');
    }
    putchar('\n');

    return 0;
}
