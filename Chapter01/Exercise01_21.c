/****************************************************
//
// Filename: Exercise01_21.c
//
// DESCRIPTION:
//  Replaces strings of blanks by a minimum number
//  of tabs and blanks.
//
****************************************************/

#include <stdio.h>
#define TABSTOPS 8

/*************************** 
//
// name: main
//
// Description: See above
//
***************************/

int main(int argc, char *argv[])
{
    int input, blanks, column;

    blanks = column = 0;

    while ((input = getchar()) != EOF)
    {
        if (input == ' ')
        {
            ++blanks;
        }
        else
        {
            while (blanks)
            {
                column = (column + 1) % TABSTOPS;

                if (blanks >= TABSTOPS)
                {
                    printf("%c", '\t');
                    blanks -= TABSTOPS - column + 1;
                }
                else
                {
                    printf("%c", ' ');
                    --blanks;
                }
            }

            column = (input == '\n') ? 0 : (column + 1) % TABSTOPS;
            printf("%c", input);
        }
    }

    return 0;
}
