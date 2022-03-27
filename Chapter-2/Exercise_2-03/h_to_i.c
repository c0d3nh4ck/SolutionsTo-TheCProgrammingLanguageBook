#include <stdlib.h>
#include <stdio.h>

#define MAXLEN 100

int htoi(char []);

int main()
{
    char s[MAXLEN];

    int c, i;

    for (i=0; i < MAXLEN-1 && (c=getchar())!=EOF && c != '\n'; ++i)
        s[i] = c;

    s[i] = '\0';

    int value;

    value = htoi(s);

    printf("\n==> Value of %s = %d\n", s, value);

    return 0;
}

int htoi(char s[])
{
    int value = 0;
    int numvl;

    if (s[0] != '0')
    {
        printf("\nInvalid 1st char\n");
        exit(1);
    }

    if (s[1] != 'X' && s[1] != 'x')
    {
        printf("\nInvalid 2nd char\n");
        exit(1);
    }

    for (int i=2; s[i]!='\0'; i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            numvl = s[i] - '0';
        }
        else
        {
            switch(s[i])
            {
                case 'a':
                    numvl = 10;
                    break;
                case 'b':
                    numvl = 11;
                    break;
                case 'c':
                    numvl = 12;
                    break;
                case 'd':
                    numvl = 13;
                    break;
                case 'e':
                    numvl = 14;
                    break;
                case 'f':
                    numvl = 15;
                    break;
                default:
                    printf("Invalid character");
                    exit(1);
            }
        }

        value = value * 16 + numvl;
    }

    return value;
}
