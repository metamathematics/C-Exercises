#include <stdio.h>

#define MAXLINE 1000    /* max number of characters */
#define TABSTOPS 2      /* number of tab stops */

int detab(char text[]);

/* prints input after replacing tabs with the proper number of spaces*/
int main()
{
    int text_length;
    char text[MAXLINE];
    
    while ((text_length = detab(text)) > 0)
        if (text_length > 0)
            printf("%s", text);

    return 0;
}


/* detab: reads a line into text[],
 * converts tabs into spaces,
 * and returns the length of the line*/
int detab(char text[])
{
    int input, index, i;

    for (index = 0; index < MAXLINE - 1 && (input = getchar()) != EOF && input != '\n'; index++)
    {   
        i = 0;

        if (input == '\t')
            for (i = 0; i < TABSTOPS; i++)
            {
                text[index + i] = ' ';
                index += i;
            }
        else
            text[index] = input;
    }

    if (input == '\n')
    {
        text[index] = input;
        index++;
    }

    text[index] = '\0';

    return index;
}
