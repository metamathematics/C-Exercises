/********************************************************
//
// DESCRIPTION:
//  Prints the length of the longest input line, and
//  as much as possible of the text of that line
//
********************************************************/

#include <stdio.h>
#define MAXLINE 1000

int getline(char line[], int maxline);
void copy(char to[], char from[]);

/***************************************
//
// Name:        main
//
// Description: See description above.
//
****************************************/

int main()
{
    int len, max, input;
    char line[MAXLINE], longest[MAXLINE];

    max = 0;

    while ((len = getline(line, MAXLINE)) > 0)
    {
        if (line[len - 2] != '\n')
        {
            while ((input = getchar()) != EOF && input != '\n')
                len++;

            if (input == '\n')
                len++;
        }

        if (len > max)
        {
            max = len;
            copy(longest, line);
        }
    }

    if (max > 0)
        printf("Longest line: %s\n", longest);

    printf("\nLength of longest line: %d\n", max);

    return 0;
}

/*************************************************************
//
// Name:         getline
//
// Description:  Reads a line into s and returns the length.
//
// Parameters:   s (char[]): A string array to hold the input
//
//               lim (int) :  The size of s
//
// Return value: The lenth of the line saved into s
//
*************************************************************/

int getline(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
        s[i] = c;

    if (c == '\n')
    {
        s[i] = c;
        i++;
    }

    s[i] = '\0';

    return i;
}

/****************************************************************
//
// Name:         copy
//
// Description:  Copy 'from' into 'to'; assume to is big enough.
//
// Parameters:   s (char[]): A string array to hold the input
//
//               lim (int) :  The size of s
//
// Return value: The lenth of the line saved into s
//
*****************************************************************/

void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        i++;
}
