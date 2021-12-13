#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

double F(double x)
{
    return pow(x+3,3) - 24*x;
}
double derivative_F (double x)
{
    return pow(3*(x+3),2) - 24;
}

double method_chord(double x1, double x2, double eps, double iteration, double x){
    int i = 0;
    eps=0.001;
    double start, stop;
    start = clock();
    while (fabs(F(x2)) > eps || i <= iteration){
        x1 = x2-((x2-x1)*F(x2))/(F(x2)-F(x1));
        x2 = x1-((x1-x2)*F(x1))/(F(x1)-F(x2));
        i++;
    }
    printf ("x = %.2f, f(x)=%.2f\n", x2, F(x2));
    stop = clock();
    printf("Time spent=%lf\n",(stop-start));
    return x2;
}

double half_division(double x1,double x2,double eps)
{
    double start, stop;
    start = clock();
    eps=0.001;
    double c;
    while((x2-x1)/2>eps)
    {
        c=(x1+x2)/2;
        printf ("x=%.2f, f(x)=%.4f\n", c, F(c));
        if((F(x1)*F(c))>0) x1=c;
        else x2=c;
    }
    stop = clock();
    printf("x = %.2f, f(x)=%.2f\n", c, F(c));
    printf("Time spent=%lf\n", (stop-start));
    return c;
}

double newton(double x, double eps, double iteration){
    double start, stop;
    start = clock();
    eps=0.001;
    int i = 0;
    do{
        x = x - F(x)/derivative_F(x);
        printf ("x=%.2f, iteration= %.1f, f(x)=%.4f\n", x, iteration, F(x));
        i++;
    }
    while(fabs(F(x)) > eps && i < iteration);
    printf("x = %.4f,f(x)=%.2f\n", x, F(x));
    stop = clock();
    printf("Time spent=%lf\n", (stop-start));
    return x;
}

int main() {
    double x1, x2, iteration, eps, x;
    unsigned int choice;
    printf("Enter variant\n");
    printf("1 - Chord method \n");
    printf("2 - Method of half division\n");
    printf("3 - Newton's method\n");
    scanf("%u", &choice);
    switch (choice) {
        case 1:
            printf("Enter X1\n");
            scanf("%lf", &x1);
            printf("Enter X2\n");
            scanf("%lf", &x2);
            while (F(x2)*F(x1)>0){
                printf("f(x1) and f(x2) must have opposite sings\n");
                printf("Enter X1\n");
                scanf("%lf", &x1);
                printf("Enter X2\n");
                scanf("%lf", &x2);
              }
            printf("Enter a limit on the number of iterations\n");
            scanf("%lf", &iteration);
            x=method_chord(x1, x2, iteration, eps, x);
            break;
        case 2:
            printf("Enter X1\n");
            scanf("%lf", &x1);
            printf("Enter X2\n");
            scanf("%lf", &x2);
            while (F(x2)*F(x1)>0) {
                printf("f(x1) and f(x2) must have opposite sings\n");
                printf("Enter X1\n");
                scanf("%lf", &x1);
                printf("Enter X2\n");
                scanf("%lf", &x2);
              }
            printf("Enter a limit on the number of iterations\n");
            scanf("%lf", &iteration);
            x=half_division (x1, x2, eps);
            break;
        case 3:
            printf("Enter X1\n");
            scanf("%lf", &x1);
            printf("Enter a limit on the number of iterations\n");
            scanf("%lf", &iteration);
            x=newton(x1, eps, iteration);
            break;
            }
    return 0;
 }
