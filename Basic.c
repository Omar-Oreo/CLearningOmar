#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include "Header_Files/Basic.h"
    
void ClearInput(void){
    int ch;
    while((ch = getchar()) != '\n' && ch != EOF);
}

void PressEnter(){
    printf("Press Enter to continue...");
    ClearInput();
}

void CountString(char str[]){
    char vowels[] = "aiueoAIUEO";
    int counts[] = {0,0,0,0,0,0,0,0,0,0};
    for(int i = 0; str[i] != '\0'; i++){
        for(int j = 0; vowels[j] != '\0'; j++){
            if(vowels[j] == str[i]){
                counts[j] = counts[j] + 1;
            }
        }
    }
    for(int c = 0; c < 5; c++){
        printf("Amount of %c's in the string: %d\n", vowels[c], counts[c] + counts[c+5]);
    }
}

void SeeStringDiff(int x){
    char strings[x][50];
    int same_count = 0;
    char samestrings[x][50];
    for(int i = 0; i < x; i++){
        printf("Enter a string(one word.): ");
        scanf("%49s", strings[i]);
    }
    for(int n = 0; n < x; n++){
        for(int j = n + 1; j < x; j++){
            if (!strcmp(strings[n],strings[j])){
                int found = 0;
                for(int k = 0; k < same_count; k++){
                    if(!strcmp(strings[n], samestrings[k])){
                        found = 1;
                        break;
                    }
                }
                if(!found){
                    strcpy(samestrings[same_count], strings[n]);
                    same_count++;
                }
            }
        }
    }
    printf("There are %d repeated strings.\n", same_count);
    printf("Matched strings: "); for(int c = 0; c < same_count; c++){printf("%s ", samestrings[c]);}
    printf("\n");
}

void CounterCount(int ac, char**av){
    if(ac == 1){
        printf("Please add more arguments while running the code.\n");
    }
    else{
    int Digits = 0;
    int Upper = 0;
    int Lower = 0;
    for(char *p = *(av + 1); *p != '\0'; p++){
        if(isupper(*p)){
            Upper++;
        }
        else if(islower(*p)){
            Lower++;
        }
        else if(isdigit(*p)){
            Digits++;
        }
    }
    printf("Amount of Digits: %d\n", Digits);
    printf("Amount of Uppercase letters: %d\n", Upper);
    printf("Amount of Lowercase letters: %d\n", Lower);
    }
}

void Quadratic(double a, double b, double c){
    double D;
    printf("The equation is: %gx^2 + %gx + %g\n", a, b, c);
    if(a == 0){
        printf("Please put a valid a value.\n");
        return;
    }
    D = pow(b, 2) - ((double)4 * a * c);
    printf("The D is %g\n", D);
    if(D < 0){
        printf("The D is negative, therefore there is no root.\n");
    }
    else if(D == 0){
        printf("The D is equal to zero. Therefore, there is one root.\n");
        double x0 = (-b + sqrt(D)) / (2 * a);
        printf("That root is %g.\n", x0);
    }
    else if(D > 0){
        printf("The D is higher than zero, therefore there is two seperate roots.\n");
        double x1 = (-b + sqrt(D)) / (2 * a);
        double x2 = (-b - sqrt(D)) / (2 * a);
        printf("The root with the positive is %g, while the root with the negative is %g.\n", x1, x2);
    }
}

void TrianglesMain(int a, char x){
    int inpt;
    printf("Select the type of triangle youd like to print.\n");
    printf("1. Right Triangle\n");
    printf("2. Triangle\n");
    scanf("%d", &inpt);
    switch(inpt){
        case 1:
        for(int i = 0; i < a; i++){
            for(int j = 0; j < a; j++){
                if(j == 0 || j == i || i == a - 1){
                    printf("%c", x);
                }
                else{
                    printf(" ");
                }
            }
            printf("\n");
        }
        break;
        case 2:
        for(int i = 0; i < a; i++){
            for(int s = 0; s < a - i - 1; s++){
                printf(" ");
            }
            for(int j = 0; j < 2 * i + 1; j++){
                printf("%c", x);
            }
            printf("\n");
        }
        break;
        default:
        printf("Please select a valid option.");
    }
}

void BoxesMain(int a, char x){
    int inpt;
    printf("Select the type of box youd like to draw: \n");
    printf("1. X'ed box\n");
    printf("2. Hollow Box\n");
    printf("3. Full Square\n");
    printf("4. Checkerboard Pattern\n");
    printf("Selection - ");
    scanf("%d", &inpt);
    switch(inpt){
        case 1:
        for(int i = 0; i < a; i++){
            for(int j = 0; j < a; j++){
                if(i == 0 || i + j == a - 1 || j == 0 || i == j || i == a - 1 || j == a - 1){
                    printf("%c", x);
                }
                else{
                    printf(" ");
                }
            }
            printf("\n");
        }
        break;
        case 2:
        for(int i = 0; i < a; i++){
            for(int j = 0; j < a; j++){
                if(i == 0 || j == 0 || i == a - 1 || j == a - 1){
                    printf("%c", x);
                }
                else{
                    printf(" ");
                }
            }
            printf("\n");
        }
        break;
        case 3:
        for(int i = 0; i < a; i++){
            for(int j = 0; j < a; j++){
                printf("%c", x);
            }
            printf("\n");
        }
        break;
        case 4:
        for(int i = 0; i < a; i++){
            for(int j = 0; j < a; j++){
                if(i == 0 || j == 0 || i == a - 1 || j == a - 1 || (i + j) % 2 == 0){
                    printf("%c", x);
                }
                else{
                printf(" ");
                }
            }
            printf("\n");
        }
        break;
        default:
        printf("Please choose a valid option.");
        BoxesMain(a,x);
    }
}

void ShapesMenu(int a, char x){
    int inpt;
    printf("Welcome to the shapes menu, select a shape to print:\n");
    printf("1. Square\n");
    printf("2. Triangle\n");
    printf("Select - ");
    scanf("%d", &inpt);
    switch(inpt){
        case 1:
        BoxesMain(a,x);
        break;
        case 2:
        TrianglesMain(a,x);
        break;
        default:
        printf("Please choose a valid option.");
        ShapesMenu(a, x);
    }
}

void Swapping(int *a, int *b, int *c){
    int temp = 0;
    int *tp = &temp;
    printf("Swapping the first integer for the second, the second for the third, and the third for the first.\n");
    *tp = *c;
    *c = *b;
    *b = *a;
    *a = *tp;
    printf("Swapped integers: %d %d %d\n", *a, *b, *c);
}

void basic_main(int argc, char**argv){
    printf("Welcome. \n\n");
    for(;;){
        int Selection;
        printf("Select the thing youd like to do: \n");
        printf("---====----====---===----====---\n");
        printf("0. Exit.\n");
        printf("1. The Quadratic Formula Calculator\n");
        printf("2. String Counter\n");
        printf("3. Argument Counter\n");
        printf("4. Integer swapper\n");
        printf("5. Shapes Drawer\n");
        printf("6. Strings checker\n");
        printf("---====----====---===----====---\n");
        printf("Select - ");
        scanf("%d", &Selection);
        switch (Selection){
            case 0:
                return;
            case 1:
                double a1,b1,c1;
                printf("Enter a, b and c of your equation: ");
                scanf("%lf %lf %lf", &a1, &b1, &c1);
                ClearInput();
                Quadratic(a1,b1,c1);
                PressEnter();
            break;
            case 2:
                char str1[50];
                printf("Enter a string: ");
                scanf("%s", str1);
                ClearInput();
                CountString(str1);
                PressEnter();
            break;
            case 3:
                printf("Counting arguments...\n");
                ClearInput();
                CounterCount(argc,argv);
                PressEnter();
            break;
            case 4:
                int e,f,g;
                printf("Enter three integers: ");
                scanf("%d %d %d", &e, &f, &g);
                ClearInput();
                Swapping(&e,&f,&g);
                PressEnter();
            break;
            case 5:
                int size;
                char Char;
                printf("Enter the size, and the character youd like to draw: ");
                scanf("%d %c", &size, &Char);
                ClearInput();
                ShapesMenu(size,Char);
                ClearInput();
                PressEnter();
            break;
            case 6:
                int x3;
                printf("Please enter the amount of strings you would like to use:");
                scanf("%d", &x3);
                SeeStringDiff(x3);
                ClearInput();
                PressEnter();
                break;
            default:
                printf("Please enter a valid option.\n");
        }
    }
    return;
}