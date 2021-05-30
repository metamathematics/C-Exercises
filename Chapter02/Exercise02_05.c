/*********************************************
//
// File:        Exercise02_05.c
//
// Author:      Mr. Young
//
// Description: Executes the any function.
//
**********************************************/
#include <stdio.h>
#include <string.h>

int any(char*, char*);

/*******************************************************************
//
// Name:            main
//
// Description:     Gets the arguments to put into any. Then
//                  calls any and prints the return value.
//
// Parameters:      argc (int) - The number of arguments this
//                               program was called with. Should
//                               be 3.
//
//                  argv (char**) - An array of the arguments this
//                                  program was called with. Should
//                                  be 3:
//                                  1) The executable
//                                  2) The first parameter for any
//                                  3) The second paramter for any
//
// Return Value(s): 0
//
*******************************************************************/
int main(int argc, char *argv[])
{
    int index;
    char s1[1000], s2[1000];
    
    s1[0] = s2[0] = '\0';
    
    strcpy(s1, argv[1]);
    strcpy(s2, argv[2]);

    index = any(s1, s2);

    printf("%d\n", index);
    return 0;
}

/*************************************************************************
//
// Name:            any
//
// Description:     Compares 2 strings, s1 and s2. Then returns the 
//                  index of the first occurance in s1, of a letter 
//                  in s2.
//
// Parameters:      s1 (char*) - The string in which the index is
//                               checked.
//
//                  s2 (char*) - The string that is the source of
//                               the letters to compare.
//                               
//
// Return Value(s): The index of the first occurance (in s1) of a letter 
//                  from s2. Else, -1.
//
*************************************************************************/
int any(char *s1, char *s2)
{
    int i, j, k, index;
    char letters[1000], c;

    index = -1;
    letters[0] = '\0';

    for (i = j = 0; index == -1 && s2[i] != '\0'; i++)
    {
        c = s2[i];

        if (strchr(letters, c) == NULL)
        {
            letters[j] = c;
            letters[++j] = '\0';

            for (k = 0; index == -1 && s1[k] != '\0'; k++)
            {
                if (s1[k] == c)
                    index = k;
            }
        }
    }

    return index;
}
