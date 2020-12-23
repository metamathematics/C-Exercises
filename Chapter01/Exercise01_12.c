/************************************
//
// DESCRIPTION:
//  Prints input one word per line.
//
*************************************/

#include <stdio.h>

int main(int argc, char *argv[])
{
    int input, escape;

    escape = 0;

    while ((input = getchar()) != EOF)
    {
        if (input == ' ' || input == '\n' || input == '\t')
        {
            if (++escape <= 1)
                putchar('\n');
        } 
        else 
        {
            escape = 0;
            putchar(input);
        }
    }
    
    return 0;
}
