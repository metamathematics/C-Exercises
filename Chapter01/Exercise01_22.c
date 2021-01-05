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
int hasWhiteSpace(char[], int*);
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
    int input, index,
    char temp[MAX], line[MAX];

    index = 0;

    while ((input = getchar()) != EOF)
    {
        if (index < MAX)
        {
            (input == '\n') ? index = print(line, index) : line[i++] = input;
        }
        else if (line[MAX-1] != ' ' && line[MAX-1] != '\t' && hasWhiteSpace(line, &index))
        {
            copy(temp, line, index, MAX);
            print(line, index);
            copy(line, temp, 0, i = (MAX-1));

            array[index++] = input
        }
        else
        {
            index = print(line, MAX);
            line[index++] = input;
        }
    }
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
//               pos (int *) : A pointer to the int that will be set to
//                             the position of the last space/tab
//
// Return Value: 0 : if no space/tab found
//               1 : if a space/tab is found
//
************************************************************************/

int hasWhiteSpace(char array[], int *pos)
{
    return 0;
}

/********************************************************************************
//
// Name:         copy
//
// Description:  Copies the a subet of one char array to another.
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
    
}
