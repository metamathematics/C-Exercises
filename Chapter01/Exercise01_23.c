/******************************************
//
// Filename: Exercise01_23.c
//
// DESCRIPTION:
//  Removes all comments from a C program.
//
*******************************************/

#include <stdio.h>

/**************************
//
// Name: main
//
// Description: See above.
//
***************************/

int main(int argc, char *argv[])
{
    int comment, openTag1, openTag2, closeTag1, closeTag2, search;

    while ((openTag1 = getchar()) != EOF)
    {
        if (openTag1 == '/')
        {
            openTag2 = getchar();

            if (openTag2 != '*')
            {
                putchar(openTag1);
                putchar(openTag2);
            }
            else
            {
                closeTag1 = openTag2;

                search = 1;
                do
                {
                    closeTag2 = getchar();

                    if ((closeTag1 == '*') && (closeTag2 == '/'))
                    {
                        search = 0;
                    }
                    else
                    {
                        closeTag1 = closeTag2;
                    }
                } while (search);
            }
        }
        else
        {
            putchar(openTag1);
        }
    }
}
