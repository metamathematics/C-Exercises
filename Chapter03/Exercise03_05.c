#include <math.h>
#include <stdio.h>

void itob(int, char[], int);
char toHex(int);

/* Tests the itob function */
int main(int arc, char* argv[])
{
   char s[1000];

   itob(30, s, 16);

   return 0; 
}

/* itob: converts n to base b as a string s */
void itob(int n, char s[], int b)
{
    int i, j, k, m;

    k = floor(log(n) / log(b));

    for (i = 0; n > 0; i++)
    {
        for (j = 1; (m = n - (pow(b, k) * j)) >= 0; j++);
        j--;
        if (b == 16 && j >= 10 && j <= 15)
            s[i] = toHex(j);
        else
            s[i] = (j) + '0';

        n -= pow(b, k) * j;
        k--;
    }
    
    while (k-- >= 0)
    {
        s[i++] = '0';
    }
    s[i] = '\0';
}

/* toHex: converts digit to a hex letter. assumes 10 <= digit <= 15 */
char toHex(int digit)
{
    char alpha;

    switch (digit)
    {
        case 10: alpha = 'A';
                 break;
        case 11: alpha = 'B';
                 break;
        case 12: alpha = 'C';
                 break;
        case 13: alpha = 'D';
                 break;
        case 14: alpha = 'E';
                 break;
        case 15: alpha = 'F';
                 break;
    }

    return alpha;
}
