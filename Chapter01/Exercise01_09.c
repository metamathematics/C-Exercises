/*****************************************
//
// DESCRIPTION:
//  Prints input and replaces multiple
//  blanks with just one.
//
*****************************************/

#include <stdio.h>

int main(int argc, char *argv[])
{
    int input, blanks;

    while ((input = getchar()) != EOF)
    {
        blanks = 0;

        while (input == ' ')
        {
            blanks = 1;
            input = getchar();
        }
        
        if (blanks)
            putchar(' ');

        putchar(input);
    }

    return 0;
}
