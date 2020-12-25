/*****************************************
//
// DESCRIPTION:
//  Prints a Fahreneit vs Celsius table.
//
******************************************/

#include <stdio.h>

#define MIN 0
#define MAX 300
#define STEP 20

float toCelsius(int);

/******************************************
//
// Name: main
//
// Description: See above for description.
//
********************************************/

int main(int argc, char *argv[]) 
{
    int fahr;

    printf("%5s %10s\n", "F", "C");
    printf("------------------------\n");

    for (fahr = MIN; fahr <= MAX; fahr += STEP)
        printf("%6d %12.2f\n", fahr, toCelsius(fahr));

    return 0;
}

/***********************************************************
//
// Name:         toCelsius
//
// Description:  Converts Fahrenheit to Celsius.
//
// Parameter:    fahrenheit (float) : The Fahreneit value
//                                    to be converted to 
//                                    Celsius.
//
// Return Value: The Celsius equivalent to the Fahrenheit
//
*************************************************************/

float toCelsius(int fahrenheit)
{
    return (5.0 / 9.0) * (fahrenheit - 32);
}
