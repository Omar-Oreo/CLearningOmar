#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
    
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

void Swappping(int a, int b, int c){
    int temp = 0;
    printf("Swapping the first integer for the second, the second for the third, and the third for the first.\n");
    temp = c;
    c = b;
    b = a;
    a = temp;
    printf("Swapped integers: %d %d %d\n", a, b, c);
}

int main(int argc, char**argv){
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
        printf("---====----====---===----====---\n");
        printf("Select - ");
        scanf("%d", &Selection);
        switch (Selection){
            case 0:
            exit(0);
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
            case 4:
            int e,f,g;
            printf("Enter three integers: ");
            scanf("%d %d %d", &e, &f, &g);
            ClearInput();
            Swappping(e,f,g);
            PressEnter();
            break;
            default:
            printf("Please enter a valid option.\n");
        }
    }

    return 0;
}