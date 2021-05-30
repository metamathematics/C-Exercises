/******************************
//
// Filename: Exercise02_02.c
//
// Author: Mr. Young
//
******************************/

#include <stdio.h>
#include <string.h>

/********************************************************************************
//
// Name: main
//
// Description: Demonstrates a for loop equivalent to 
//              for (i = 0; i < lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
//                  s[i] = c;
//              without using && or ||
//
********************************************************************************/

int main(int argc, char *argv[])
{
    int i, lim;
    char s[100], c;

    lim = 100;
    s[0] = '\0';

    for (i = 0; i < lim - 1; ++i)
    {
        if ((c = getchar()) != '\n')
        {
            if (c != EOF)
            {
                s[i] = c;
            }
        }
    }

    if (strlen(s) > 0)
        printf("%s\n", s);
    else
        printf("s is empty\n");

    return 0;
}
