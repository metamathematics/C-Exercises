#include <stdio.h>
#define MAXLINE 1000    /* maximum input line size */

int getline(char line[], int maxline);
void reverse(char line[], int length, char reverse_line[]);

/* prints the input in reverse */
int main()
{
    int len;                    /* current line length */
    char line[MAXLINE];         /* current input line */
    char reverse_line[MAXLINE]; /* input in reverse */

    while ((len = getline(line, MAXLINE)) > 0)
    {
        reverse(line, len, reverse_line);
        printf("%s\n", reverse_line);
    }

    return 0;
}


/* getline: read a line into s, return length */
int getline(char s[], int lim)
{
    int input, line_length;

    for (line_length = 0; line_length < lim - 1 && (input = getchar()) != EOF && input != '\n'; line_length++)
        s[line_length] = input;

    s[line_length] = '\0';

    return line_length;
}


/* reverse: saves the reverse of array line into array reverse_line */
void reverse(char line[], int length, char reverse_line[])
{
    int index;

    for (index = length - 1; index >= 0; index--)
        reverse_line[(length - 1) - index] = line[index];
    
    reverse_line[length] = '\0';
}
