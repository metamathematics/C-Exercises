#include <math.h>
#include <string.h>
#include <stdio.h>

char toHex(int);
int toInt(char *);
void toStr(char *, int);
void itob(int, char[], int);
void reverseStr(char *, int, int);

/* Tests the itob function */
int main(int arc, char* argv[])
{
    char s[1000];
    s[0] = '\0';
   
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
        for (j = 1; (m = n - (pow(b, k) * j)) >= 0; j++)
        {
            /* no statements */    
        }
        
        j--;

        if (b == 16 && j >= 10 && j <= 15)
            s[i] = toHex(j);
        else
            if (j < 10)
                s[i] = (j) + '0';
            else
            {
                toStr(s, j);    
            }

        n -= pow(b, k) * j;
        k--;
    }
    
    while (k-- >= 0)
    {
        s[i++] = '0';
    }
    s[i] = '\0';
}

void toStr(char *str, int num)
{
    char temp[100];
    int i, n;
    int last_char = strlen(str) - 1;

    for (i = 0; num > 0; i++)
    {
        temp[i] = (num % 10) + '0';
        num /= 10;
    }

    temp[i] = '\0';
    
    reverseStr(temp, 0, strlen(temp) - 1);
    strcat(str, temp);
}

/*reverseStr: reverses the string*/
void reverseStr(char *str, int start, int end)
{
    char temp;

    if (start < end)
    {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        reverseStr(str, ++start, --end);
    }
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

    for (i = 0; str[i] != '\0'; i++)
        num += (str[i] - '0') * pow(10, strlen(str) - (i + 1));

    return num;
}
