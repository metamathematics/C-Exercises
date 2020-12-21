/**************************************
//
// DESCRIPTION:
//  Counts blanks, newlines, and tabs.
//
**************************************/

#include <stdio.h>

int main(int argc, char *argv[])
{
    int input;
    long blanks, newlines, tabs;

    blanks = newlines = tabs = 0;

    while ((input = getchar()) != EOF)
    {
        switch (input)
        {
            case ' ' : blanks++;
                       break;

            case '\n' : newlines++;
                        break;

            case '\t' : tabs++;
                        break;
        }
    }

    printf("blanks: %ld \nnewlines: %ld \ntabs: %ld\n", blanks, newlines, tabs);

    return 0;
}
