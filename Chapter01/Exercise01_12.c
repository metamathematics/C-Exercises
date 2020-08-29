#include <stdio.h>

/* Prints input as one word per line */
int main()
{
    int input, nonword;

    input = getchar();

    nonword = 0;

    while (input != EOF)
    {
        if (input == ' ' || input == '\n' || input == '\t')
        {
            nonword++;
            
            if (nonword == 1)
                putchar('\n');
            
        } else {
            putchar(input);
            nonword = 0;
        }

        input = getchar();
    }

    return 0;
}
