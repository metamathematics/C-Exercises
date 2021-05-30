#include <stdio.h>
#include <string.h>

void squeeze(char*, char*);

int main(int argc, char *argv[])
{
    char s1[1000], s2[1000];

    s1[0] = s2[0] = '\0';

    strcpy(s1, argv[1]);
    strcpy(s2, argv[2]);

    squeeze(s1, s2);
    printf("%s\n", s1);
    return 0;
}

void squeeze(char *s1, char *s2)
{
    int i, j, k, m;
    char letters[1000], c;

    letters[0] = '\0';

    for (i = m = 0; s2[i] != '\0'; i++)
    {
        c = s2[i];        

        if (strchr(letters, c) == NULL)
        {
            letters[m++] = c;
            letters[m] ='\0';

            for (j = k = 0; s1[j] != '\0'; j++)
            {
                if (s1[j] != c)
                    s1[k++] = s1[j];
            }
            s1[k] = '\0';
        }
    }
}
