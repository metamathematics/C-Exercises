/************************************************
//
// DESCRIPTION:
//  Replaces each tab, newline, and backslash
//  with their respective escape sequence.
//
************************************************/

#include <stdio.h>

int main(int argc, char *argv[])
{
    int input;

    while ((input = getchar()) != EOF)
    {
        switch (input)
        {
            case '\t' : printf("\\t");
                        break;
            case '\n' : printf("\\n");
                        putchar('\n');
                        break;
            case '\\' : printf("\\\\");
                        break;
            default:
                putchar(input);
        }
    }

    putchar('\n');

    return 0;
}
