#include <stdio.h>
#include "Header_Files/Utils.h"

void ClearInput(void){
    int ch;
    while((ch = getchar()) != '\n' && ch != EOF);
}

void PressEnter(void){
    printf("Press Enter to continue...");
    ClearInput();
}
