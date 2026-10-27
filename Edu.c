#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
    
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

int main(){
    printf("Welcome. \n\n");
    for(;;){
        int Selection;
        printf("Select the thing youd like to do: \n");
        printf("---====----====---===----====---\n");
        printf("0. Exit.\n");
        printf("1. The Quadratic Formula Calculator\n");
        printf("2. String Counter\n");
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
            Quadratic(a1,b1,c1);
            break;
            case 2:
            char str1[50];
            printf("Enter a string: ");
            scanf("%s", str1);
            ClearInput();
            CountString(str1);
            PressEnter();
            break;
            default:
            printf("Please enter a valid option.\n");
        }
    }

    return 0;
}