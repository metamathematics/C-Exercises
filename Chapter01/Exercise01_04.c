/***********************************
//
// DESCRIPTION:
//  Converts Celsius to Fahrenheit
//
***********************************/

#include <stdio.h>

int main(int argc, char *argv[]) {
    int cels;
    float fahr;

    printf("%5s %10s\n", "C", "F");
    printf("-----------------------\n");

    for (cels = -20; cels <= 160; cels += 10) {
        fahr = (9.0 / 5.0) * cels + 32;
        printf("%6d %12.2f\n", cels, fahr);
    }

    return 0;
}
