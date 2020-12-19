/***************************************** 
//
// DESCRIPTION:
//  Converts from Fahrenheit to Celsius
//  from 300 to 0
//
****************************************/

#include <stdio.h>

int main(int argc, char *argv[]) {
    int fahr;
    float cels;

    printf("%5s %10s\n", "F", "C");
    printf("---------------------\n");

    for (fahr = 300; fahr >= 0; fahr -= 20) {
        cels = (5.0 / 9.0) * (fahr - 32);
        printf("%6d %12.2f\n", fahr, cels);
    }

    return 0;
}
