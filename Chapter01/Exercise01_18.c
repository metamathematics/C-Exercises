/*****************************************************
//
// Filename: Exercise01_18.c
//
// DESCRIPTION:
//  Removes trailing blanks and tabs from each line
//  of input, and deletes entire blank lines.
//
*****************************************************/

#include <stdio.h>
#include <string.h>
#define MAXLEN 1000

/********************************
//
// Name:        main
//
// Description: See above.
//
********************************/

int main(int argc, char *argv[])
{
    int len;
    char input[MAXLEN];

    while (fgets(input, MAXLEN, stdin) != NULL)
    {
        while ((len = strlen(input)) && (input[len - 2] == ' ' || input[len - 2] == '\t'))
        {
            input[len - 2] = input[len - 1];
            input[len - 1] = '\0';
        }

        if (input[0] != '\n')
            printf("%s", input);
    }
    
    return 0;
}
