/*************************************************************
//
// File:        Exercise02_06.c
//
// Author:      Mr. Young
//
// Description: Executes the setbits function.
//
**************************************************************/

#include <stdio.h>
#include <string.h>

#define SIZE 1000

void shift(char*);
unsigned rightoperand(int);
unsigned setbits(unsigned, int, int, unsigned);

/*************************************************************
//
//
//
//
//
//
//
//
**************************************************************/
int main(int argc, char *argv[])
{
    unsigned result;

    result = setbits(0xAF, 2, 6, 0x7A);
    printf("%X\n", result);

    return 0;
}

/*************************************************************
//
//
//
//
//
//
//
//
**************************************************************/
unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    unsigned operand, rightmost;

    operand = rightoperand(n);
    rightmost = y & operand;

    return rightmost;
}

/*************************************************************
//
//
//
//
//
//
//
//
**************************************************************/
unsigned rightoperand(int n)
{
    unsigned operand;
    char numstr[SIZE] = "0x";

    while (n > 0)
    {
        if (n - 4 >= 0)
        {
            n -= 4;
            shift(numstr);
            numstr[2] = 'F';
        }
        else if (n == 3)
        {
            n = 0;
            shift(numstr);
            numstr[2] = '7';
        }
        else if (n == 2)
        {
            n = 0;
            shift(numstr);
            numstr[2] = '3';
        }
        else if (n == 1)
        {
            n = 0;
            shift(numstr);
            numstr[2] = '1';
        }
    }

    sscanf(numstr, "%X", &operand);

    return operand;
}

/*************************************************************
//
//
//
//
//
//
//
//
**************************************************************/
void shift(char *str)
{
    int i;

    for (i = strlen(str); i > 1; i--)
        str[i + 1] = str[i];
}
