#include <stdio.h>

#define MAXLEN 100

int any(char [], char []);

int main()
{
    char s1[MAXLEN], s2[MAXLEN];
    int position;

    printf("\nInput the 1st and 2nd string : ");
    scanf("%s", s1);
    scanf("%s", s2);

    position = any(s1, s2);

    printf("\nFirst location of the character found at : %d\n", position);

    return 0;
}

int any(char s1[], char s2[])
{
    for (int i=0; s2[i] != '\0'; i++)
    {
        int k=0;
        for (int j=0; s1[j] != '\0'; j++)
        {
            if (s1[j] == s2[i])
                return j+1;
        }
    }

    return -1;
}
