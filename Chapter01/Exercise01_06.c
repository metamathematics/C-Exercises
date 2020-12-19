/******************************************
//
// DESCREPTION:
//  Checks the value of getchar() 1= EOF
//
******************************************/

#include <stdio.h>

int main(int argc, char *argv[]) {
    int input;
    char trash[100];
    char continueInput = 1;
    
    while (continueInput) {
        printf("\nType any character and press enter (ctrl+d for EOF) >> ");
        input = (getchar() != EOF);
        printf(input ? "%s %d" : "\n%s %d", "getchar() != EOF:", input);
        
        if (input)
            fgets(trash, 100, stdin);

        printf("\nDo you want to continue?\n");
        printf("(y or n) >> ");
        continueInput = (getchar() == 'y') ? 1 : 0;
        fgets(trash, 100, stdin);
    }

    return 0;
}
