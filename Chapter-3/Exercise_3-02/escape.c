#include <stdio.h>
#define BUFF 1000

void escape(char* t, char* s)
{
    int i, j=0;
    for (i=0; s[i] != '\0'; i++, j++)
    {
        char c = s[i];
        
        switch (c)
        {
            case '\n':
                t[j++] = '\\';
                t[j] = 'n';
                break;
            case '\t':
                t[j++] = '\\';
                t[j] = 't';
                break;
            default:
                t[j] = c;
                break;
        }
    }

    t[j] = '\0';
}

void unescape(char* t, char* s)
{
    int i, j=0;
    for (i=0; t[i] != '\0'; i++, j++)
    {
        switch(t[i])
        {
            case '\\':
                switch(t[++i])
                {
                    case 'n':
                        s[j] = '\n';
                        break;
                    case 't':
                        s[j] = '\t';
                        break;
                    default:
                        s[j] = '\\';
                        s[++j] = t[i];
                        break;
                }
                break;
            default:
                s[j] = t[i];
                break;
        }
    }
    
    s[j] = '\0';
}

int main()
{
    int i, c;
    char s[BUFF], t[BUFF];

    for (i=0; i<BUFF-1 && (c=getchar()) != EOF; ++i)
    {
        s[i] = c;
    }
    s[i] = '\0';

    escape(t, s);
    printf("ESCAPE: %s\n", t);
    unescape(t, s);
    printf("UNESCAPE: %s\n", s);

    return 0;
}
