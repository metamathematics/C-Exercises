/**************************************************
//
// DESCRIPTION:
//  Make a histogram of frequencies of different
//  characters from input.
//
**************************************************/

#include <stdio.h>
#include <stdlib.h>

struct character 
{
    int ch;
    int freq;
    struct character *next;
};

/*****************************************
//
// Name: main
//
// Description: See description above.
//
******************************************/

int main(int argc, char *argv[])
{
    int input, max;
    struct character *start, *current, *previous, *node;

    start = NULL;

    while ((input = getchar()) != EOF)
    {
        if (start == NULL)
        {
            start = (struct character *) malloc(sizeof(struct character));
            start->ch = input;
            start->freq = 1;
            start->next = NULL;
        }

        current = previous = start;

        while (current != NULL && input < current->ch)
        {
            previous = current;
            current = current->next;
        }
        
        if (current == NULL || input > current->ch)
        {
            node = (struct character *) malloc(sizeof(struct character));
            node->ch = input;
            node->freq = 1;

            if (current == start)
            {
                node->next = start->next;
                start = node;
            }
            else
            {
                previous->next = node;
                node->next = current;
            }
        }
        else
        {
            (current->freq)++;
        }
    }

    /* Find the max frequency */
    current = start;
    max = current->freq;

    while (current != NULL)
    {
        if (current->freq > max)
            max = current->freq;

        current = current->next;
    }


    /* Print the histogram */
    while (max > 0)
    {
        current = start;

        while (current != NULL)
        {
            if (current->freq >= max)
            {
                printf(" #");
            }
            else
            {
                printf("  ");
            }

            current = current->next;
        }

        putchar('\n');
        max--;
    }

    /* Print the x-axis */
    current = start;

    while (current != NULL)
    {
        input = current->ch;

        if (input == '\n')
            printf("\\n");

        else if (input == '\t')
            printf("\\t");

        else
            printf(" %c", input);

        current = current->next;
    }

    putchar('\n');

    return 0;
}
