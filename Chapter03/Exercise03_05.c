#include <math.h>
#include <string.h>
#include <stdio.h>

void itob(int, char[], int);
char toHex(int);

/* Tests the itob function */
int main(int arc, char* argv[])
{
    char s[1000];
   
    if (arc != 3)
        printf("Usage: ./Exercise03_05 positiveInteger1 positiveInteger2\n");
    else
    {
        itob(toInt(argv[1]), s, toInt(argv[2]));
        printf("%s\n", s);
    }

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
            s[i] = (j) + '0';/* need case for when j > 9 */

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

/* toInt: convert str to an int. assumes str is nonneg. */
int toInt(char *str)
{
    int i, num = 0;

    for (i = 0; i < strlen(str); i++)
        num += (str[i] - '0') * pow(10, strlen(str) - (i + 1));

    return num;
}
