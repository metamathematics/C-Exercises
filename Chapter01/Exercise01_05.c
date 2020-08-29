#include <stdio.h>

/* Print Fahrenheit-Celsius table
 *  for fahr = 300, 280, ..., 20, 0 */
int main()
{
    int fahr;

    printf("\n   Fahrenheit    Celsius\n");
    printf("---------------------------\n");

    for (fahr = 300; fahr >= 0; fahr -= 20)
    {
        printf("%10d %11.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
    }

    printf("\n");

    return 0;
}
