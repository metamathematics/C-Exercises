#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>

double log2(double);

/* Determines the length of char, short, int, long, both signed and unsigned*/
int main(int arc, char *argv[])
{
    long int_max, int_min;
    double long_max, long_min, uint_max, ulong_max;
    
    printf("\n----Signed Types----\n");

    printf("\nThe max char is: %d\n", CHAR_MAX);
    printf("The min char is: %d\n", CHAR_MIN);
    printf("Length of char: %.0f bits\n", log2(CHAR_MAX - CHAR_MIN));

    printf("\nThe max short is: %d\n", SHRT_MAX);
    printf("The min short is: %d\n", SHRT_MIN);
    printf("Length of short: %.0f bits\n", log2(SHRT_MAX - SHRT_MIN));
    
    int_max = INT_MAX; 
    int_min = INT_MIN;
    printf("\nThe max int is: %d\n", INT_MAX);
    printf("The min int is: %d\n", INT_MIN);
    printf("Length of int: %.0f bits\n", log2((int_max - int_min)));
    
    long_max = LONG_MAX; 
    long_min = LONG_MIN;
    printf("\nThe max long is: %.0f\n", long_max);
    printf("The min long is: %.0f\n", long_min);
    printf("Length of long: %.0f bits\n", log2((long_max - long_min)));

    printf("\n\n----Unsigned Types----\n");

    printf("\nThe max unsigned char is: %d\n", UCHAR_MAX);
    printf("Length of unsigned char: %.0f bits\n", log2(UCHAR_MAX));

    printf("\nThe max unsigned short is: %d\n", USHRT_MAX);
    printf("Length of unsigned short: %.0f bits\n", log2(USHRT_MAX));
    
    uint_max = UINT_MAX; 
    printf("\nThe max unsigned int is: %.0f\n", uint_max);
    printf("Length of unsigned int: %.0f bits\n", log2((uint_max)));
    
    ulong_max = ULONG_MAX; 
    printf("\nThe max unsigned long is: %.0f\n", ulong_max);
    printf("Length of unsigned long: %.0f bits\n\n", log2((ulong_max)));
    
    return 0;
}

double log2(double x)
{
    return log(x) / log(2);
}
