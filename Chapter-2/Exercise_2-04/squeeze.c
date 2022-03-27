#include <stdio.h>

#define MAXLEN 100

void squeeze(char [], char []);

int main()
{
    char s1[MAXLEN], s2[MAXLEN];

    printf("\nInput the 1st and 2nd string : ");
    scanf("%s", s1);
    scanf("%s", s2);

    squeeze(s1, s2);

    printf("\nThe new string : %s\n", s1);

    return 0;
}

void squeeze(char s1[], char s2[])
{
    for (int i=0; s2[i] != '\0'; i++)
    {
        int k=0;
        for (int j=0; s1[j] != '\0'; j++)
        {
            if (s1[j] != s2[i])
                s1[k++] = s1[j];
        }
        s1[k] = '\0';
    }
}
