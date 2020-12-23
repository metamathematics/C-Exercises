/*********************************************
//
// DESCRIPTION:
//  Makes a histogram of the lengths of
//  words from the user input.
//
*********************************************/

#include <stdio.h>
#define LEN 11

int max(int[], int);

/*********************************************
//
// NAME:        main
//
// DESCRIPTION: See description above.
//
*********************************************/

int main(int argc, char *argv[])
{
    int input, word, total_stats[LEN];
    int i, j, global_max, local_max;
    
    input = word = 0;

    for (i = 0; i < LEN; i++)
        total_stats[i] = 0;

    while ((input = getchar()) != EOF)
    {
        if (input != ' ' && input != '\t' && input != '\n')
        {
            word++;
        }
        else
        {
            if (word)
                total_stats[word]++;

            word = 0;
        }
    }

    global_max = total_stats[max(total_stats, LEN)];
    printf("\n|\n");

    for (i = 0; i < global_max; i++)
    {
        printf("| ");

        local_max = total_stats[max(total_stats, LEN)];

        for (j = 0; j < LEN; j++)
        {
            if (total_stats[j] == local_max)
            {
                printf("# ");
                total_stats[j]--;
            }
            else
            {
                printf("  ");
            }
        }
        
        putchar('\n');
    }

    for (i = 0; i < LEN + 1; i++)
        printf("==");

    printf("\n  ");
    
    for (i = 0; i < LEN; i++)
        printf("%d ", i);

    putchar('\n');
    
    return 0;
}

/****************************************************
//
// NAME:        max
//
// DESCRIPTION: Finds the max number in the array.
//
// PARAMETERS:  num (int[]) : An array of ints
//
//              len (int) : The length of the array
//
// RETURN VAL:  The index of the max number
//
*****************************************************/

int max(int num[], int len)
{
    int index, max_num, max_index;

    max_num = num[0];
    max_index = 0;

    for (index = 1; index < len; index++)
    {
        if (num[index] > max_num)
        {
            max_num = num[index];
            max_index = index;
        }
    }
    
    return max_index;
}
