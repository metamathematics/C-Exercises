#include <stdio.h>

/* Counts blanks, tabs, and newlines */

int main()
{
    int input, blanks, tabs, newlines;

    blanks = 0;
    tabs = 0;
    newlines = 0;

    input = getchar();

    while (input != EOF)
    {
        if (input == ' ')
            blanks++;
        
        if (input == '\t')
            tabs++;
        
        if (input == '\n')
            newlines++;

        input = getchar();
    }

    printf("blanks = %d \ntabs = %d \nnewlines = %d\n", blanks, tabs, newlines);

    return 0;
}
