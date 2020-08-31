#include <stdio.h>
#define MAXLINE 1000    /* maximum input line size */
#define MINLINE 80      /* minimum input line size */

int getline(char line[], int maxline);

/* prints all input line longer than 80 characters.*/
int main()
{
    int len;            /* current line length */
    char line[MAXLINE];     /* current input line */

    while ((len = getline(line, MAXLINE)) > 0)
    {
        if (len > MINLINE)
            printf("%s", line);
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
