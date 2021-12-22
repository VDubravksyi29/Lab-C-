#ifndef LABA4_MATRIX_H
#define LABA4_MATRIX_H

int i, j, k;
int na;
int max;
int nb;
int mb;
int temp;
int total;

int matrix_max (na) {
    int matrix[na][na];
    max;
    for (i = 0; i < na; i++) {
        for (j = 0; j < na; j++) {
            matrix[i][j] = 10 + rand() % (20 - 10 + 1);
            printf("%d ", matrix[i][j]);
            if(matrix[i][j] > max)
            {
                max = matrix[i][j];
            }

        }
        puts("\n");
    }
    printf("Max value of the matrix element- %d;\n", max);
}

int matrix_trans (nb, mb) {
    int matrix[nb][mb];
    int matrix_trans[nb][mb];
    printf("Matrix B\n");
    for (i = 0; i < nb; i++) {
        for (j = 0; j < mb; j++) {
            matrix[i][j] = 10 + rand() % (20 - 10 + 1);
            printf("%d ", matrix[i][j]);
        }
        puts("\n");
    }
    printf("Transposed matrix B\n");
    for (i = 0; i < mb; i++) {
        for (j = 0; j < nb; j++) {
            matrix_trans[i][j] = matrix[j][i];
            printf("%d ", matrix_trans[i][j]);
        }
        puts("\n");
    }
}

int matrix_mnoj (nb, mb, na) {
    double matrix_a[na][na];
    double matrix_b[nb][mb];
    double matrix_c[nb][mb];
    printf("Matrix A\n");
    for (i = 0; i < na; i++) {
        for (j = 0; j < na; j++) {
            matrix_a[i][j] = 10 + rand() % (20 - 10 + 1);
            printf("%.0f ", matrix_a[i][j]);
        }
        puts("\n");
    }
    printf("Matrix B\n");
    for (i = 0; i < nb; i++) {
        for (j = 0; j < mb; j++) {
            matrix_b[i][j] = 10 + rand() % (20 - 10 + 1);
            printf("%.0f ", matrix_b[i][j]);
        }
        puts("\n");
    }
    printf("Matrix C\n");
    for (i = 0; i < nb; i++) {
        for (j = 0; j < mb; j++) {
            matrix_c[i][j] += matrix_a[i][j] * matrix_b[i][j];
            printf("%.0f ", matrix_c[i][j]);
        }
        puts("\n");
    }
}

int matrix_sort(int nb, int mb) {
    double matrix_b[nb][mb];
    for (i = 0; i < nb; i++) {
        for (j = 0; j < mb; j++) {
            matrix_b[i][j] = 10 + rand() % (20 - 10 + 1);
            printf("%.0f ", matrix_b[i][j]);
        }
        puts("\n");
    }
    for (i = 0; i < mb; i++) {
        for (k = i + 1; k < mb; k++) {
            if (matrix_b[0][i] > matrix_b[0][k]) {
                for (j = 0; j < nb; j++) {
                    temp = matrix_b[j][i];
                    matrix_b[j][i] = matrix_b[j][k];
                    matrix_b[j][k] = temp;
                }
            }
        }
    }

    for (i = 0; i < nb; i++)
    {
        for (j = 0; j < mb; j++) {
            printf("%.0f ", matrix_b[i][j]);
        }
        puts("\n");
    }
}

int matrix_sum (nb, mb) {
    double matrix_b[nb][mb];
    printf("Matrix \n");
    for (i = 0; i < nb; i++) {
        for (j = 0; j < mb; j++) {
            matrix_b[i][j] = 10 + rand() % (20 - 10 + 1);
            printf("%.0f ", matrix_b[i][j]);
        }
        puts("\n");
    }
    for(i = 0; i<nb; ++i){
        total = 0;
        for(j = 0; j<mb; ++j){
            total += matrix_b[i][j];
        }
        printf("Sum elements of row ");
        printf("%d - ",i+1);
        printf("%d \n", total);
    }
    printf("\n\n");
    for(i = 0; i<nb; ++i){
        total = 0;
        for(j = 0; j<nb; ++j){
            total += matrix_b[i][j];
        }
        printf("Sum elements of columns ");
        printf("%d - ",i+1);
        printf("%d \n", total);
    }
}
#endif
