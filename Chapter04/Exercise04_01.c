/* Write the funciton strrindex(s,t), which returns the position of the 
   rightmost occurence of t in s, or -1 if there is none. */

#include <string.h>
#include <stdio.h>
#define MAXLINE 1000

int strrindex(char *, char *);

/* Tests strrindex*/
int main(int argc, char *argv[])
{
    char pattern[10], target[1000];
    int index;

    printf("Enter a sentence: ");
    fgets(target, 1000, stdin);
    target[strlen(target) - 1] = '\0';

    printf("Enter a pattern (<10 chars): ");
    scanf("%s", pattern);

    index = strrindex(target, pattern);
    printf("The index of the rightmost occurance of pattern %s is: %d\n", pattern, index);

    return 0;
}

/* strrindex: return index of the rightmost occurance of t in s.*/
int strrindex(char *s, char *t)
{
    int i, j, k;
    int index = -1;

    for (i = 0; s[i] != '\0'; i++)
    {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            index = i;
    }

    return index;
}
