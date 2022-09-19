#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#define MAXOP 100   // max size of operand or operator
#define NUMBER '0'  // signal that a number was found
#define IDENTIFIER 1
#define ENDSTRING 2
#define MAX_ID_LEN 32
#define MAXVARS 30

struct varType {
    char name[MAX_ID_LEN];
    double val;
};

int getop(char []);
void push(double);
double pop();
void printop();
void duplicate();
void clearStack();
void swapItems();
void funcname(char [], struct varType []);
void varname(char s[], struct varType var[]);
void clearStacks(struct varType []);

int pos=0;
struct varType last;


/* reverse Polish calculator */
int main()
{
    int type;
    double op2;
    char s[MAXOP];
    struct varType var[MAXVARS];

    clearStacks(var);

    while ((type = getop(s)) != EOF)
    {
        switch (type) 
        {
            case NUMBER:
                push(atof(s));
                break;
            case IDENTIFIER:
                funcname(s, var);
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '%':
                op2 = pop();
                if (op2 != 0.0)
                    push(fmod(pop(), op2));
                else
                    printf("error: zero divisor\n");
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            case '$':
                swapItems();
                break;
            case '@':
                printop();
                break;
            case '#':
                clearStacks(var);
                break;
            case '&':
                duplicate();
                break;
            case ENDSTRING:
                break;
            case '=':
                printf("=> %lf\n", pop());
                int nm = pop();
                printf("=> %d\n", nm);
                var[pos].val = nm;
                last.val = var[pos].val;
                push(last.val);
                break;
            case '<':
                printf("The last variable used was: %s (value == %g)\n", last.name, last.val);
                break;
            default:
                printf("error: unknow command %s\n", s);
                break;
        }
    }
    
    return 0;
}


#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void push(double f) {
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full can't push %g\n", f);
}

double pop() {
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}


#include <ctype.h>

int getch(void);
void ungetch(int);

int getop(char s[])
{
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';

    if isalpha(c)
    {
        i = 0;
        while (isalpha(s[i++] = c))
            c = getch();
        s[i-1] = '\0';
        if (c!=EOF)
            ungetch(c);
        return IDENTIFIER;
    }

    if (!isdigit(c) && c != '.')
    {
        if ('=' == c && '\n' == (getch()))
        {
            ungetch('\0');
            return c;
        }
        if ('\0' == c)
            return ENDSTRING;

        return c;
    }

    i = 0;
    if (isdigit(c))
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE];      // buffer for ungetch
int bufp = 0;           // next free position in buf

/* get a (possibly push-back) character */
int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

/* push character back on input */
void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

/* print top element of the stack without popping */
void printop()
{
    if (sp > 0)
        printf("Top of the stack is : %8g\n", val[sp-1]);
    else
        printf("The stack is empty\n");
}

/* duplicate the element at top of the stack */
void duplicate()
{
    double tmp = pop();
    push(tmp);
    push(tmp);
}

/* swap two items on top of the stack */
void swapItems()
{
    double tmp1 = pop();
    double tmp2 = pop();
    push(tmp1);
    push(tmp2);
}

/* clear the stack */
void clearStack()
{
    sp = 0;
}

/* to calculate the value of some mathematical functions */
void funcname(char s[], struct varType var[])
{
    double tmp1;

    if (strcmp(s, "cos") == 0)
        push(cos(pop()));
    else if (strcmp(s, "sin") == 0)
        push(sin(pop()));
    else if (strcmp(s, "exp") == 0)
        push(exp(pop()));
    else if (strcmp(s, "pow")  == 0)
    {
        tmp1 = pop();
        push(pow(pop(), tmp1));
    }
    else
    {
        varname(s, var);
    }
}

void clearStacks(struct varType var[]) 
{
    int i;

    sp = 0;

    for (i=0; i < MAXVARS; ++i)
    {
        var[i].name[0] = '\0';
        var[i].val = 0.0;
    }
}

void varname(char s[], struct varType var[])
{
    int i = 0;

    while (var[i].name[0] != '\0' && i < MAXVARS - 1)
    {
        if(!strcmp(s, var[i].name))
        {
            strcpy(last.name, s);
            last.val = var[i].val;
            push(var[i].val);
            pos = i;
            return;
        }
        i++;
    }
    strcpy(var[i].name, s);
    strcpy(last.name, s);
    push(var[i].val);
    pos = i;
}
