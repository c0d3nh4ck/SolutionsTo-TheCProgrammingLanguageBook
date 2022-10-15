#include <stdio.h>
#include <string.h>

void reverse(char s[], int, int);

int main()
{
    char s[] = "reverse it";
    reverse(s, 0, strlen(s) - 1);
    printf("%s\n", s);
    return 0;
}

void reverse(char s[], int l, int r)
{
   char temp;
   if (l < r)
   {
       reverse(s, l+1, r-1);
       temp = s[l];
       s[l] = s[r];
       s[r] = temp;
   }
}
