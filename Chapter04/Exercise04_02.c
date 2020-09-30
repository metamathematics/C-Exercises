/* Extend atof to handle scientific notation of the form 123.45e-6,
   where a floating-point number may ne followed by e or E and an
   optionally signed exponent.
   */

#include <ctype.h>
#include <stdio.h>
#include <string.h>

double atof(char *);

/* Tests the atof function */
int main(int argc, char *argv[])
{
    printf("%f\n", atof(argv[1]));

    return 0;
}

/* atof: converts string s to double */
double atof(char *s)
{
    double val, power, num;;
    int i, sign;

    for (i = 0; isspace(s[i]); i++)
        ;

    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;

    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');

    if (s[i] == '.')
        i++;

    for (power = 1.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }

    val = sign * val / power;
    printf("b4 e:%f\n", val);

    if (i < strlen(s))
    {
        if (s[i] == 'E' || s[i] == 'e')
        {
            i++;
            sign = 1;
            if (s[i] == '-' || s[i] == '+')
            {
                if (s[i] == '-')
                    sign = 0;
                i++;
            }
            
            if (isdigit(s[i]))
            {
                for (num = 0; s[i] != '\0' ; i++)
                    num = 10 * num + (s[i] - '0');

                for (i = 1, power = 1.0; i <= num  ; i++)
                    power *= 10.0;

                if (sign)
                    val *=  power;
                else
                    val /= power;
            }
        }
    }

    return val;
}
