#include <stdio.h>

void escape(char[], char[]);

/* Tests the escape() function */
int main(int arc, char *argv[])
{
    char s[1000];
    char t[] = "This is a\ttest.\nThis is only a\ttest.\n\"What is your name?\"\n\tShe said.\n\"They call me \'Skull-Face\'\n\tHe replied.";

    escape(s, t);
    printf("%s\n%s\n", t, s);

    return 0;
}
/* escape: converts specific characters into visible escape sequences. */
void escape(char s[], char t[])
{
    int i, j;

    for (i = j = 0; t[i] != '\0'; i++)
    {
        switch (t[i])
        {
            case '\n': s[j++] = '\\';
                       s[j++] = 'n';
                       break;
            case '\t': s[j++] = '\\';
                       s[j++] = 't';
                       break;
            case '\'': s[j++] = '\\';
                       s[j++] = '\'';
                       break;
            case '\"': s[j++] = '\\';
                       s[j++] = '\"';
                       break;
            default: s[j++] = t[i];
        }
    }
}
