#include <stdio.h>
#include <stdlib.h>

#include "Header_Files/Basic.h"
#include "Header_Files/Intermediate.h"

int main(int argc, char **argv){
    int inpt;
    printf("Welcome to the main menu!\n");
    printf("Run: \n");
    printf("1 - Basic.c (Beginner level C)");
    printf("2 - Intermediate (Low level C)");
    scanf("%d", &inpt);
    switch(inpt){
        case 1:
        basic_main(argc, argv);
        break;
        case 2:
        intermediate_main();
        break;
        default:
        printf("Please select a valid option. Exiting...");
        return 1;
    }
    return 0;
}