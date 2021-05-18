/**********************************
//
// Filename: Exercise02_01.c
//
// Author: Mr. Young
//
**********************************/

#include <float.h>
#include <limits.h>
#include <stdio.h>

void userinterface(void);
int optionselect(int);
void charinfo(void);
void shortinfo(void);
void intinfo(void);
void longinfo(void);

/*****************************************************************
//
// Name:        main
//
// Description: Prints the ranges of char, short, int, and long.
//
*****************************************************************/
int main(int argc, char *argv[])
{
    int option, keepgoing = 1;

    while (keepgoing)
    {    
        userinterface();
        scanf("%d", &option);
        keepgoing = optionselect(option);
    }

    return 0;
}

/*********************************************
//
// Name:            userinterface
//
// Description:     The UI of the program.
//
// Parameters:      None
//
// Return Value(s): none
//
**********************************************/
void userinterface()
{
    printf("\nSelect the appropiate option for the given datatype to view its range (enter 0 to quit):\n");
    printf("1) char \n2) short \n3) int \n4) long \n>> ");
}

int optionselect(int option)
{
    switch(option)
    {
        case 0: printf("Good Bye\n");
                break;

       case 1: charinfo();
               break;

       case 2: shortinfo();
               break;

       case 3: intinfo();
               break;

       case 4: longinfo();
               break;

       default: printf("Invalid Entry");
    }

    return option ? 1 : 0;
}

/**********************************************
//
// Name:            charinfo
//
// Description:     Display the ranges of char
//
// Parameters:      none
//
// Return Value(s): none
//
***********************************************/
void charinfo()
{
    printf("\n=== range of char ===\n");
    printf("\n-signed char-\n");
    printf("min: %d\n", 0);
    printf("max: %d\n", UCHAR_MAX);

    printf("\n-usigned char-\n");
    printf("min: %d\n", CHAR_MIN);
    printf("max: %d\n", CHAR_MAX);
    printf("\n=== === === ===\n");
}

/**********************************************
//
// Name:            shortinfo
//
// Description:     Display the ranges of short
//
// Parameters:      none
//
// Return Value(s): none
//
***********************************************/
void shortinfo()
{
    printf("\n=== range of short ===\n");
    printf("\n-signed short-\n");
    printf("min: %d\n", 0);
    printf("max: %d\n", USHRT_MAX);

    printf("\n-usigned short-\n");
    printf("min: %d\n", SHRT_MIN);
    printf("max: %d\n", SHRT_MAX);
    printf("\n=== === === ===\n");
}

/**********************************************
//
// Name:            intinfo
//
// Description:     Display the ranges of int
//
// Parameters:      none
//
// Return Value(s): none
//
***********************************************/
void intinfo()
{
    printf("\n=== range of int ===\n");
    printf("\n-usigned int-\n");
    printf("min: %d\n", 0);
    printf("max: %u\n", UINT_MAX);

    printf("\n-signed int-\n");
    printf("min: %d\n", INT_MIN);
    printf("max: %d\n", INT_MAX);
    printf("\n=== === === ===\n");
}

/**********************************************
//
// Name:            longinfo
//
// Description:     Display the ranges of long
//
// Parameters:      none
//
// Return Value(s): none
//
***********************************************/
void longinfo()
{
    printf("\n=== range of long ===\n");
    printf("\n-usigned long-\n");
    printf("min: %d\n", 0);
    printf("max: %lu\n", ULONG_MAX);

    printf("\n-signed long-\n");
    printf("min: %ld\n", LONG_MIN);
    printf("max: %ld\n", LONG_MAX);
    printf("\n=== === === ===\n");
}
