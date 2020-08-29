#include <stdio.h>

/* Copies input to output, while replacing strings
 *  with one or more blanks with just one.*/
int main()
{
    int input, blanks;

    blanks = 0;

    input = getchar();

    while (input != EOF)
    {
        while (input == ' ')
        {
            blanks++;
            
            if (blanks == 1)
                putchar(input);
            
            input = getchar();
        }

        blanks = 0;
        putchar(input);
        input = getchar();
    }

    return 0;
}
