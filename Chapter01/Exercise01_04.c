#include <stdio.h>

/* Print Celsius-Fahrenheit table
 *  for celsius = -20, 0, 20, ..., 220 */
int main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = -20;    /* lower linit of temperature table */
    upper = 220;    /* upper limit */
    step = 20;      /* step size */

    printf("\n Celsius    Fahrenheit\n");
    printf("---------------------------\n");

    celsius = lower;
    while (celsius <= upper)
    {
        fahr = ((9.0 / 5.0) * celsius) + 32.0;
        printf("%6.0f %12.1f\n", celsius, fahr);
        celsius += step;
    }

    printf("\n");

    return 0;
}
