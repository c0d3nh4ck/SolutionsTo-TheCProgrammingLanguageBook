#include <ctype.h>
#include <stdio.h>
#define MAXLINE 100

int get_line(char line[], int max);
double atof(char str[]);

int main()
{
    double sum;
    char line[MAXLINE];

    sum = 0;
    while (get_line(line, MAXLINE) > 0)
        printf("=> %g\n", sum += atof(line));

    return 0;
}

/* atof: convert string to floating point value */
double atof(char s[])
{
    int i;
    double sign, val, power;

    for (i=0; isspace(s[i]); i++)
        ;

    sign = (s[i] == '-') ? -1 : 1;

    if (s[i] == '+' || s[i] == '-')
        i++;

    for (val=0.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] -'0');
    }

    if (s[i] == '.')
        i++;
        
    for (power = 1.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    
    
    if (s[i] == 'e')
    {
        i++;
        int powsign = (s[i] == '-') ? -1 : 1;

        if (s[i] == '+' || s[i] == '-')
            i++;

        int exp;
        for (exp=0; isdigit(s[i]); i++)
        {
            exp = 10 * exp + (s[i] - '0');
        }

        double exp_value;
        for (exp_value = 1.0; exp!=0; exp--)
        {
            exp_value *= 10.0;
        }

        if (powsign == -1)
            power *= exp_value;
        else
            power /= exp_value;
    }

    return sign * val / power;
}

/* get_line: get line into s, return length */
int get_line(char s[], int lim)
{
    int c, i;

    i = 0;
    while (--lim > 0 && (c= getchar())!=EOF && c != '\n')
    {
        s[i++] = c;
    }

    if (c == '\n')
        s[i++] = c;

    s[i] = '\0';
    return i;
}

