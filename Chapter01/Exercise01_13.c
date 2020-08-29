#include <stdio.h>

#define ARRAY_LENGTH 100

/* prints a histogram of the lengths of up to ARRAY_LENGTH words in input */
int main()
{
    int input, index, max_length, word_count, height;
    int word_lengths[ARRAY_LENGTH];

    max_length = word_count = 0;

    for (index = 0; index < ARRAY_LENGTH; index++)
        word_lengths[index] = 0;
    
    input = getchar();
    index = 0;

    /* save word lengths to an array */
    /* find max word length. this is the height of the histogram */
    while (input != EOF &&  word_count <= ARRAY_LENGTH)
    {
        if (input == ' ' || input == '\n' || input == '\t')
        {
            if (word_lengths[index] > 0)
            {
                index++;
                word_count++;
            }
        }
        else
        {
            word_lengths[index]++;

            if (word_lengths[index] > max_length)
                max_length = word_lengths[index];
        }

        input = getchar();
    }

    /* loop on the height of the histogram down to 0. */
    for (height = max_length; height >= 0; height--)
    {
        /* print a space for each word length < height and a dash for each word legnth >= height*/
        for (index = 0; index < ARRAY_LENGTH; index++)
        {
            if (height == 0)
                putchar('=');
            else if (word_lengths[index] < height)
                putchar(' ');
            else
                printf("%d", word_lengths[index]);
        }

        putchar('\n');
    }

    return 0;
}
