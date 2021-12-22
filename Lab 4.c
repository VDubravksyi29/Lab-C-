#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "matrix_lab4.h"

int main() {
    int na, nb, mb;
    unsigned int choice;
    printf("Enter variant\n");
    printf("1 - Find max element of the matrix A\n");
    printf("2 - Transpose the matrix B\n");
    printf("3 - Find the product of matrices A x B\n");
    printf("4 - Sort row by ascending\n");
    printf("5 - Print the sum of the elements of rows A and B\n");
    scanf("%u", &choice);
    switch (choice) {
        case 1:
            printf("Enter the number of columns and rows A \n");
            scanf("%d", &na);
            printf("Matrix A\n");
            matrix_max(na);
            return 0;
        case 2:
            printf("Enter the number of rows B\n");
            scanf("%d", &nb);
            printf("Enter the number of columns B\n");
            scanf("%d", &mb);
            matrix_trans(nb,mb);
            return 0;
        case 3:
            printf("Enter the number of columns and rows A \n");
            scanf("%d", &na);
            printf("Enter the number of rows B\n");
            scanf("%d", &nb);
            printf("Enter the number of columns B\n");
            scanf("%d", &mb);
            if (nb != mb && nb != na) {
                printf("Error. Matrix B must be similar as matrix A\n");
                return 0;
            }
            else {
                matrix_mnoj(nb,mb,na);
            }
            return 0;
        case 4:
            printf("Enter the number of rows B\n");
            scanf("%d", &nb);
            printf("Enter the number of columns B\n");
            scanf("%d", &mb);
            matrix_sort(nb,mb);
            return 0;
        case 5:
            printf("Enter the number of rows B\n");
            scanf("%d", &nb);
            printf("Enter the number of columns B\n");
            scanf("%d", &mb);
            matrix_sum(nb,mb);
            return 0;
    }
}
