#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

void oblojka()
{
    printf("===============\n");
    printf("=  F  =   S   =\n");
    printf("===============\n");
}

double funct(double x)
{
        return pow(1+x,-1);
}

double leftrekt(double a, double b, int n){
    double h = (b - a) / n;
    double s = 0;
    for(int i = 0; i <= n - 1;++i){
        s += h * funct(a + i * h);
    }

    return s;
}

double rightrekt(double a, double b, int n){
    double h = (b - a) / n;
    double s = 0;
    for(int i = 0; i <= n;i++){
        s += h * funct(a + i * h);
    }

    return s;
}

double trapeze(double a, double b, int n){
    double h = (b - a) / n;
    double s = funct(a) + funct(b);
    for(int i = 0;i <= n - 1;i++){
        s += 2 * funct(a+ i * h);
    }
    s *= h / 2;

    return s;
}

double parabola(double a, double b, int n){
    double h = (b - a) / n;
    double s = funct(a) + funct(b);
    int k = 0;
    for(int i = 0;i <= n - 1;i++){
        k = 2 + 2 * (i % 2);
        s += k * funct(a + i * h);
    }
    s *= h / 3;

    return s;
}

void clrscr()
{
    system("cls||clear");
}

int main() {
    double n1, n2, n, result_of_ing_calc;
    unsigned int choice;
    printf("Chose variant  \n");
    printf("1 - Left rectangles method \n");
    printf("2 - Right rectangles method \n");
    printf("3 - Trapezoid method\n");
    printf("4 - Parabolic method\n");
    scanf("%u", &choice);
    switch (choice) {
        case 1:
            printf("Enter the lower limit\n");
            scanf("%lf", &n1);
            printf("Enter the upper limit\n");
            scanf("%lf", &n2);
            printf("Enter step\n");
            scanf("%lf", &n);
            oblojka();
            result_of_ing_calc=leftrekt(n1,n2,n);
            printf("Integral result's is - %.2lf",result_of_ing_calc);
            return 0;
        case 2:
            printf("Enter the lower limit\n");
            scanf("%lf", &n1);
            printf("Enter the upper limit\n");
            scanf("%lf", &n2);
            printf("Enter step\n");
            scanf("%lf", &n);
            oblojka();
            result_of_ing_calc=rightrekt(n1,n2,n);
            printf("Integral result's is - %.2lf",result_of_ing_calc);
            return 0;
        case 3:
            printf("Enter the lower limit\n");
            scanf("%lf", &n1);
            printf("Enter the upper limit\n");
            scanf("%lf", &n2);
            printf("Enter step\n");
            scanf("%lf", &n);
            oblojka();
            result_of_ing_calc=trapeze(n1,n2,n);
            printf("Integral result's is - %.2lf",result_of_ing_calc);
            return 0;
        case 4:
            printf("Enter the lower limit\n");
            scanf("%lf", &n1);
            printf("Enter the upper limit\n");
            scanf("%lf", &n2);
            printf("Enter step\n");
            scanf("%lf", &n);
            oblojka();
            result_of_ing_calc=parabola(n1,n2,n);
            printf("Integral result's is - %.2lf",result_of_ing_calc);
            return 0;
    }
    return 0;
}
