/*******************************************
//
// Filename: Exercise01_19.c
//
// DESCRIPTION:
//  Reverses the input a line at a time.
//
********************************************/

#include <stdio.h>
#include <string.h>

#define MAXLEN 1000

void reverse(char*);

/*****************************
//
// Name: main
//
// Decription: See above.
//
*****************************/

int main(int argc, char *argv[])
{
    char input[MAXLEN];

    while (fgets(input, MAXLEN, stdin) != NULL)
    {
        reverse(input);
        printf("%s", input);
    }

    printf("\n");
    
    return 0;
}

/***************************************************
//
// Name:         reverse
//
// Description:  Reverses the character string s.
//
// Paramters:    s (char*) : The character string
//                            to reverse
//
// Return value: none
//
****************************************************/

void reverse(char *s)
{
    int temp, i, j;

    for (i = strlen(s) - 1, j = 0; i > j; i--, j++)
    {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}
