#include <stdio.h>
#include <stdlib.h> // for atof() function
#include <math.h>

#define MAXOP 100   // max size of operand or operator
#define NUMBER '0'  // signal that a number was found
#define MAXLINE 1000

int getop(char []);
void push(double);
double pop();
void printop();
void duplicate();
void clearStack();
void swapItems();
int get_line(char [], int);

char line[MAXLINE];
int line_i;

/* reverse Polish calculator */
int main()
{
    int type;
    double op2;
    char s[MAXOP];

    while (get_line(line, MAXLINE) != 0)
    {
        line_i = 0;
        while ((type = getop(s)) != '\0')
        {
            switch (type) 
            {
                case NUMBER:
                    push(atof(s));
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
                    clearStack();
                    break;
                case '&':
                    duplicate();
                    break;
                default:
                    printf("error: unknow command %s\n", s);
                    break;
            }
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

int get_line(char s[], int lim)
{
    int c, i;
    
    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';

    return i;
}


#include <ctype.h>

int getop(char s[])
{
    int i, c;

    while ((s[0] = c = line[line_i++]) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c;
    i = 0;
    if (isdigit(c))
        while (isdigit(s[++i] = c = line[line_i++]))
            ;
    if (c == '.')
        while (isdigit(s[++i] = c = line[line_i++]))
            ;
    s[i] = '\0';
    line_i--;

    return NUMBER;
}

#define BUFSIZE 100


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
