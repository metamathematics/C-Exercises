/******************************************************
//
// Filename: Exercise01_20.c
//
// DESCRIPTION:
//  Replaces tabs in the input with the proper number
//  of blanks to space to the next tab stop.
//
*******************************************************/

#include <stdio.h>
#define TABSTOP 4

/*****************************
//
// Name: main
//
// Description: See above.
//
*****************************/

int main(int argc, char *argv[])
{
    int columns, blanks, input;

    columns = 0;

    while ((input = getchar()) != EOF)
    {
        if (input == '\t')
        {
            blanks = TABSTOP - columns;

            while (blanks--)
            {
                printf("%c", ' ');
                columns = (columns + 1) % TABSTOP;
            }
        }
        else
        {
            columns = (input == '\n') ? 0 : (columns + 1) % TABSTOP;
            printf("%c", input);
        }
    }

    return 0;
}
