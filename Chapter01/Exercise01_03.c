#include <stdio.h>

/* Print Fahrenheit-Celsius table
 *  for fahr = 0, 20, ..., 300 */
int main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;      /* lower linit of temperature table */
    upper = 300;    /* upper limit */
    step = 20;      /* step size */

    printf("\n   Fahrenheit    Celsius\n");
    printf("---------------------------\n");

    fahr = lower;
    while (fahr <= upper)
    {
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("%10.0f %11.1f\n", fahr, celsius);
        fahr += step;
    }

    printf("\n");

    return 0;
}
