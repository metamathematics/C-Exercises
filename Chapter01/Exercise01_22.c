/***************************************************
//
// Filename: Exercise01_22.c
//
// DESCRIPTION:
//  Folds long input lines into two or more lines.
//
***************************************************/

#include <stdio.h>
#define MAX 80

int print(char[], int);
int hasWhiteSpace(char[], int, int*);
void copy(char[], char[], int, int);

/***********************************
//
// Name: main
//
// Description: See above.
//
************************************/

int main(int argc, char *argv[])
{
    int input, index;
    char temp[MAX+1], line[MAX+1];

    index = 0;

    while ((input = getchar()) != EOF)
    {
        if (index < MAX)
        {
            (input == '\n') ? index = print(line, index) : (line[index++] = input);
        }
        else if (line[MAX-1] != ' ' && line[MAX-1] != '\t' && hasWhiteSpace(line, MAX, &index))
        {
            copy(temp, line, index, MAX);
            print(line, index);
            copy(line, temp, 0, (index = (MAX-1)));

            line[index++] = input;
        }
        else
        {
            index = print(line, MAX);
            line[index++] = input;
        }
    }

    return 0;
}

/***********************************************************************
//
// Name:         print
//
// Description:  Prints the contents of the given char array from
//               the begining up to the specified index.
//
// Parameters:   array (char[]) :  The array containing the contents
//                                 to be printed
//
//               max (int) : The point after which to stop printing
//
// Return Value: 0
//
***********************************************************************/

int print(char array[], int max)
{
    array[max] = '\0';
    printf("%s\n", array);

    return 0;
}

/************************************************************************
//
// Name:         hasWhiteSpace
//
// Description:  Checks if the given char array has a space or a tab.
//               If true, it sets the given int to the index of the 
//               last space/tab.
//
// Parameters:   array (char[]) : The char array to search
//
//               len (int) : The length of the array
//
//               pos (int *) : A pointer to the int that will be set to
//                             the position of the last space/tab
//
// Return Value: 0 : if no space/tab found
//               1 : if a space/tab is found
//
************************************************************************/

int hasWhiteSpace(char array[], int len, int *pos)
{
    int index;

    *pos = -1;

    for (index = len - 1; index >= 0 && *pos >= 0; index++)
    {
        if (array[index] == ' ' || array[index] == '\t')
            *pos = index;
    }

    return (*pos < 0) ? 0 : 1;
}

/********************************************************************************
//
// Name:         copy
//
// Description:  Copies the a subset of one char array to another.
//
// Parameters:   original (char[]) : The char array to be copied from
//
//               subArray (char[]) : The char array to copy to
//
//               start (int) : The position in original to begin the copy
//
//               end (int) : The position in original after the end of the copy
//
// Return Value: none
//
**********************************************************************************/

void copy(char subArray[], char original[], int start, int end)
{
    int i, j;

    for (i = 0, j = start; j < end; i++, j++)
        subArray[i] = original[j]; 
}
