#include <stdio.h>

int main()
{
    int c; 
    c = 1;

    while (c == 1) 
    {
        c = (getchar() != EOF);
        printf("%d\n", c);
    }

    return 0;
}
