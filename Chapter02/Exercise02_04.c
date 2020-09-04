#include <stdio.h>
#include <string.h>

void squeeze(char[], char[]);

/* prompts the user for 2 strings
 * then deletes all chars in the the first string that match chars in the second
 * displays the result*/
int main(int arc, char *argv[])
{
    char s1[1000], s2[1000];

    printf("Enter two strings: ");
    scanf("%s %s", s1, s2);
    
    squeeze(s1, s2);
    printf("%s\n", s1);

    return 0;
}

void squeeze(char s1[], char s2[])
{
    int i, j, k;

    for (i = 0; s2[i] != '\0'; i++)
    {
        for (j = k = 0; s1[j] != '\0'; j++)
            if (s1[j] != s2[i])
                s1[k++] = s1[j];
        s1[k] = '\0';
    }    
}
