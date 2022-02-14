#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

float fahrtocel(float fahr)
{
    return (5.0 / 9.0) * (fahr - 32.0);
}

int main()
{
    float fahr, celsius;

    fahr = LOWER;
    
    printf("\nFahrenheit\tCelsius\n");
    printf("----------\t-------\n");

    while (fahr <=  UPPER)
    {
        celsius = fahrtocel(fahr);
        printf("%4.0f\t\t%6.2f\n", fahr, celsius);
        fahr += STEP;
    }
}

