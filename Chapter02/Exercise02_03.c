#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int hexToDec(char [], int);

/* Converts hex to dec */
int main(int arc, char *argv[])
{
    int decimal = -1;
    char hex[1000];
    
    printf("Enter a hexadecimal: ");
    scanf("%s", hex);

    /* if first 2 chars are '0' and ('x' or 'X') */
    if (hex[0] == '0' && toupper(hex[1]) == 'X')
        decimal = hexToDec(hex, 2);
    else
        decimal = hexToDec(hex, 0);

    if (decimal < 0)
        printf("Error: %s is not a hexadecimal\n", hex);
    else
        printf("%s in decimal is %d\n", hex, decimal);

    return 0;
}

int hexToDec(char hex[], int position)
{
    int index, dec;

    dec = 0;

    for (index = position; hex[index] != '\0' && dec >= 0; index++)
    {
        if (isdigit(hex[index]))
            dec +=(hex[index] - '0') * pow(16, (strlen(hex) - (index + 1)));
        else if (isxdigit(hex[index]))
        {
            hex[index] = toupper(hex[index]);
            dec += ((hex[index] - 'A') + 10) * pow(16, (strlen(hex) - (index + 1)));
        }
        else
            dec = -1;
    }

    return dec;
}
