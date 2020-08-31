#include <stdio.h>
#define MAXLINE 1000    /* maximum input line size */

int getline(char line[], int maxline);
void copy(char to[], char from[]);

/* prints the length of arbitrarily long input lines,
 *  and as much as possible of the text.*/
int main()
{
    int len;            /* current line length */
    int max;            /* maximum length seen so far */
    char line[MAXLINE];     /* current input line */
    char longest[MAXLINE];  /* longest line saved here */

    max = 0;
    while ((len = getline(line, MAXLINE)) > 0)
    {
        if (len > max)
        {
            max = len;
            copy(longest, line);
        }
    }

    if (max > 0)    /* there was a line */
    {    
        printf("\nLength of longest line: %d\n", max);
        printf("Longest line: %s\n", longest);
    }

    return 0;
}


/* getline: read a line into s, return length */
int getline(char s[], int lim)
{
    int input, line_length;

    line_length = 0;

    while ((input = getchar()) != EOF && input != '\n')
    {
        if (line_length < lim - 1)
            s[line_length] = input;

        line_length++;
    }

    if (input == '\n')
    {
        s[line_length] = input;
        line_length++;
    }

    s[line_length] = '\0';

    return line_length;
}


/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        i++;
}
