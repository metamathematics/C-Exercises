#include <stdio.h>
#include <string.h>

int any(char*, char*);

int main(int argc, char *argv[])
{
    int index;
    char s1[1000], s2[1000];
    
    s1[0] = s2[0] = '\0';
    
    strcpy(s1, argv[1]);
    strcpy(s2, argv[2]);

    index = any(s1, s2);

    printf("%d\n", index);
    return 0;
}

int any(char *s1, char *s2)
{
    int i, j, k, index;
    char letters[1000], c;

    index = -1;
    letters[0] = '\0';

    for (i = j = 0; index == -1 && s2[i] != '\0'; i++)
    {
        c = s2[i];

        if (strchr(letters, c) == NULL)
        {
            letters[j] = c;
            letters[++j] = '\0';

            for (k = 0; index == -1 && s1[k] != '\0'; k++)
            {
                if (s1[k] == c)
                    index = k;
            }
        }
    }

    return index;
}
