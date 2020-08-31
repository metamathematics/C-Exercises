#include <stdio.h>

float fahr_to_cel(int);

/* Prints a conversion table of Fahrenheit to Celsius */
int main()
{
    int fahr;

    printf("\n%18s %15s\n", "Fahrenheit", "Celsius");
    printf("     -------------------------------\n");
    
    for (fahr = 0; fahr <= 300; fahr += 20)
    {
        printf("%15d %17.1f\n", fahr, fahr_to_cel(fahr));
    }

    putchar('\n');

    return 0;
}

/* Converts Fahrenheit to Celsius */
float fahr_to_cel(int fahr)
{
    return (5.0 / 9.0) * (fahr - 32);
}
