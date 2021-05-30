/***********************************************
//
// File: Exercise02_04.c
//
// Author: Mr. Young
//
// Description: Executes the squeeze function.
//
***********************************************/

#include <stdio.h>
#include <string.h>

void squeeze(char*, char*);

/**************************************************************************
//
// Name:            main
//
// Description:     Compares two strings (s1 and s2). All letters in
//                  s1 that are also in s2, are deleted from s1. Then
//                  s1 is printed.
//
// Parameters:      argc (int) - The number of arguments used to call
//                               this program. This number should be 3.
//
//                  argv (char**) - An array of all the the arguments
//                                  used to call this function. There
//                                  should be three arguments:
//                                  1) The executable name
//                                  2) s1
//                                  3) s2
//
// Return Value(s): 0
//
**************************************************************************/
int main(int argc, char *argv[])
{
    char s1[1000], s2[1000];

    s1[0] = s2[0] = '\0';

    strcpy(s1, argv[1]);
    strcpy(s2, argv[2]);

    squeeze(s1, s2);
    printf("%s\n", s1);
    return 0;
}

/**************************************************************************
//
// Name:            squeeze
//
// Description:     Compares two strings (s1 and s2). All letters in
//                  s1 that are also in s2, are deleted from s1.
//
// Parameters:      s1 (char*) - The string to delete letters from.
//
//                  s2 (char*) - The string to compare to s2.
//
// Return Value(s): 0
//
**************************************************************************/
void squeeze(char *s1, char *s2)
{
    int i, j, k, m;
    char letters[1000], c;

    letters[0] = '\0';

    for (i = m = 0; s2[i] != '\0'; i++)
    {
        c = s2[i];        

        if (strchr(letters, c) == NULL)
        {
            letters[m++] = c;
            letters[m] ='\0';

            for (j = k = 0; s1[j] != '\0'; j++)
            {
                if (s1[j] != c)
                    s1[k++] = s1[j];
            }

            s1[k] = '\0';
        }
    }
}
