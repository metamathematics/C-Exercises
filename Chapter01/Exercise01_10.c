#include <stdio.h>

/* Copies input to output and
 *  replaces each tab with \t, each backspace with \b,
 *  and each backslash with \\*/
int main()
{
    int input;

    input = getchar();

    while (input != EOF)
    {
        if (input == '\t')
            printf("\\t");
        else if (input == '\b')
            printf("\\b");
        else if (input == '\\')
            printf("\\\\");
        else
            putchar(input);

        input = getchar();
    }

    return 0;
}
