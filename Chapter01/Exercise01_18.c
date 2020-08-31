#include <stdio.h>
#define MAXLINE 1000    /* maximum input line size */

int getline(char line[], int maxline);
int compact(char line[], int length);

/* removes all trailing blanks and tabs from each input line,
 *  and deletes blank lines*/
int main()
{
    int len;            /* current line length */
    char line[MAXLINE];     /* current input line */

    while ((len = getline(line, MAXLINE)) > 0)
    {
        if (compact(line, len) > 0)
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

    s[line_length] = '\0';

    return line_length;
}


/* compact: removes blanks and tabs from line[] */
int compact(char line[], int length)
{
    int index;

    if (length == 2 && (line[0] == ' ' || line[0] == '\t'))
        length = 0;
    else
    {
        index = length - 1;
        
        while (line[index] == ' ' || line[index] == '\t')
        {
            line[index] = '\0';
            index--;
        }

        length = index + 1;
    }

    return length;
}
