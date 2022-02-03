#include <stdio.h>

int main()
{
    float fahr, celsius;
    float lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    celsius = lower;
    
    printf("\nCelsius\t\tFahrenheit\n");
    printf("--------\t----------\n");

    while (celsius <=  upper)
    {
        fahr = (9.0 / 5.0) * (celsius + 32.0);
        printf("%4.0f\t\t%7.2f\n", celsius, fahr);
        celsius += step;
    }
}

