/*************************************************
//
// Filename: Exercise01_24.c
// 
// Author: Mr. Young
//
*************************************************/

#include <stdio.h>

struct {
    int parenth;
    int sqrbrac;
    int crlbrac;
} counts;

enum symbols {
    openpar = '(', closedpar = ')', 
    opensqrbrac = '[', closedsqrbrac = ']',
    opencrlbrac = '{', closedcrlbrac = '}',
    };

int checkcounts(void);
int readcomment(void);
int readstring(int);
void checksymbols(int);

/*************************************************
//
// Name: main
//
// Description:
//  Looks for unbalance parentheses and brackets.
//  Prints an error message if found.
//
*************************************************/
int main(int argc, char *argv[])
{
    /* Define variables */
    enum states { comment, string, code };

    int state, input;

    /* Initialize counts */
    state = code;
    counts.parenth = counts.sqrbrac = counts.crlbrac = 0;

    /* while not EOF, get input */
    while ((input = getchar()) != EOF)
    {
        /* Check for comments */
        if (input == '/' && state == code)
        {
            /* if EOF, exit */
            if ((input = getchar()) == EOF)
            {
                break;
            }
            /* else if comment, read til comment is over */
            else if (input == '*')
            {
                state = comment;
                
                if (readcomment())
                {
                    state = code;
                }
            }
            /* else return input to stdin stream */
            else
            {
                ungetc(input, stdin);
            }
        }
        /* else if string/char, read til string/char is over */
        else if ((input == '\'' || input == '\"') && state == code)
        {
            state = string;

            if (readstring(input))
            {
                state = code;
            }
        }
        /* else Check for each symbol */
        else
        {
            checksymbols(input);
        }
     }

     checkcounts();

     return 0;
}

/***********************************************************************************************
//
// Name:            checksymbols
//
// Description:     Checks if the symbol is a open/closed parenthese or bracket. If open, adds
//                  to the count. Closed subtracts from the count.
// 
// Parameters:      symbol (int) - The symbol to check
//
// Return Value(s): none
//
************************************************************************************************/
void checksymbols(int symbol)
{
    switch(symbol)
    {
        case openpar: ++counts.parenth;
                      break;

        case closedpar: --counts.parenth;
                        break;

        case opensqrbrac: ++counts.sqrbrac;
                          break;

        case closedsqrbrac: --counts.sqrbrac;
                            break;

        case opencrlbrac: ++counts.crlbrac;
                          break;

        case closedcrlbrac: --counts.crlbrac;
                            break;
                            
        default:;
    }
}

/********************************************************************************************
//
// Name:            readstring
//
// Description:     Reads through each chare in a string/char until the string has ended.
//
// Parameters:      quote (int) - Either \' our \". Lets us know if to read a char or string.
//
// Return Value(s): 1 - if string/char has an ending
//                  0 - otherwise
//
*********************************************************************************************/
int readstring(int quote)
{
    int input;
    enum quotes {sgle = '\'', dble = '\"'};

    if (quote == sgle)
    {
        getchar();
        input = getchar();
    }
    else
    {
        while ((input = getchar()) != EOF && input != '\"')
        {
        
        }

    }

    return (input == sgle || input == dble) ? 1 : 0;
}

/******************************************************************************************
//
// Name:            readcomment
//
// Description:     Reads through each character of a comment until the comment has ended.
//
// Parameters:      None
//
// Return Value(s): 1 - if comment has an ending
//                  0 - otherwise
//
*******************************************************************************************/
int readcomment()
{
    int input, state = 0;

    while ((input = getchar()) != EOF && state != 3)
    {
        if (input == '*')
            state = 1;
        else if (input == '/')
            state += 2;
        else
            state = 0;
    }

    return state != 3 ? 0: 1;
}

/***************************************************************************************
//
// Name:            checkcounts
//
// Description:     Checks the counts of the parentheses and brackets. If their values
//                  are not equal to 0, an error message is printed.
//
// Parameters:      None
//
// Return Value(s): 1 - if and error message was printed
//                  0 - otherwise
//
****************************************************************************************/
int checkcounts()
{
    enum bool { false, true };
    int errorPrinted = false;
   
    if (counts.parenth)
    {
        if (counts.parenth < 0)
            printf("Unbalanced parentheses. Missing a \'(\'.\n");

        if (counts.parenth > 0)
            printf("Unbalanced parentheses. Missing a \')\'.\n");

        errorPrinted = true;
    }

    if (counts.sqrbrac)
    {
        if (counts.sqrbrac < 0)
            printf("Unbalanced square brackets. Missing a \'[\'.\n");

        if (counts.sqrbrac > 0)
            printf("Unbalanced square brackets. Missing a \']\'.\n");
            
        errorPrinted = true;
    }

    if (counts.crlbrac)
    {
        if (counts.crlbrac < 0)
            printf("Unbalanced square brackets. Missing a \'{\'.\n");

        if (counts.crlbrac > 0)
            printf("Unbalanced square brackets. Missing a \'}\'.\n");
            
        errorPrinted = true;
    }

    return errorPrinted; 
}
