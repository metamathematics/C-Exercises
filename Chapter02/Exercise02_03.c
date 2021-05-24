/****************************************************
//
// File: Exercise02_03.c
//
// Description:
//  Converts a hex number to its equivalent integer.
//
*****************************************************/

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int htoi(char*);
int hex(char);

int main(int argc, char *argv[])
{
    int intnum;
    char hex[20];

    hex[0] = '\0';
    strcpy(hex, argv[1]);

    intnum = htoi(hex);

    if (intnum >= 0)
        printf("%d\n", intnum);
    else
        printf("Not a valid hex number.\n");

    return 0;
}

int htoi(char *hexnum)
{
    char c, s[2];
    int intnum, index, pwr;

    s[0] = ' ';
    s[1] = '\0';
    intnum = pwr = 0;
    index = strlen(hexnum) - 1;

    while (index >= 0)
    {
        c = hexnum[index--];
        s[0] = c;

        if (isdigit(c))
            intnum += atoi(s) * pow(16, pwr++);
        else if (isxdigit(c))
            intnum += hex(c) * pow(16, pwr++);
        else
            return -1;
    }

    return intnum;
}

int hex(char hexdigit)
{
    int intnum;

    hexdigit = toupper(hexdigit);

    switch (hexdigit)
    {
        case 'A': intnum = 10;
                  break;

        case 'B': intnum = 11;
                  break;

        case 'C': intnum = 12;
                  break;

        case 'D': intnum = 13;
                  break;

        case 'E': intnum = 14;
                  break;

        case 'F': intnum = 15;
                  break;
    }

    return intnum;
}
