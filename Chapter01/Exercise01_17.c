/********************************************
//
// DESCRIPTION:
//  Prints all input lines that are longer
//  than 80 characters.
//
********************************************/

#include <stdio.h>
#include <string.h>

#define MAXLEN 1000

/*********************************
//
// Name:        main
//
// Description: See above
//
*********************************/

int main(int argc, char *argv[])
{
    char input[MAXLEN];

    while (fgets(input, MAXLEN, stdin) != NULL)
    {
        if (strlen(input) > 80)
            printf("%s", input);
    }

    return 0;
}
