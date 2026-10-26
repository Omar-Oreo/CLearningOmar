#include <stdio.h>
#include <string.h>
#include <math.h>

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
        int x0 = (-b + sqrt(D)) / (2 * a);
        printf("That root is %d.", x0);
    }
    else if(D > 0){
        printf("The D is higher than zero, therefore there is two seperate roots.\n");
        int x1 = (-b + sqrt(D)) / (2 * a);
        int x2 = (-b - sqrt(D)) / (2 * a);
        printf("The root with the positive is %d, while the root with the negative is %d.\n", x1, x2);
    }
}

int main(){
    printf("Welcome. \n\n");
    for(;;){
        int Selection;
        printf("Select the thing youd like to do: \n");
        printf("---====----====---===----====---\n");
        printf("1. The Quadratic Formula Calculator\n");
        printf("2. String Counter\n");
        printf("---====----====---===----====---\n");
        printf("Select - ");
        scanf("%d", &Selection);
        switch (Selection){
            case 1:
            double a1,b1,c1;
            printf("Enter a, b and c of your equation: ");
            scanf("%lf %lf %lf", &a1, &b1, &c1);
            Quadratic(a1,b1,c1);
        }
    }

    return 0;
}