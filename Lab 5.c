#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include "text.c"

double fun(float x);
void save_txt(double group, double brigade, double start, double end, double dots, double step);
void save_bin(double group, double brigade, double start, double end, double dots, double step);
int head_bin (FILE *myfile_bin);
int head_txt (FILE *myfile_txt);

double fun(float x)
{
    return pow(x,3)*sin(6*x);
}

void save_txt(double group, double brigade, double start, double end, double dots, double step) {
    FILE *myfile_txt;
    int i = 0;
    double delta;
    char name_txt[] = ("../result.txt");
    myfile_txt = fopen(name_txt, "w");
    if (dots > 0) {
        fprintf(myfile_txt, "Group RS-p%.0lf\n", group);
        fprintf(myfile_txt, "Variant %.0lf\n", brigade);
        fprintf(myfile_txt, "x1=%.0lf  x2=%.0lf number of rows=%.0f\n", start, end, dots);
        head_txt(myfile_txt);
        while (i < dots && start <= end) {
            delta = (end - start) / (dots - 1);
            fprintf(myfile_txt, "|");
            fprintf(myfile_txt, "%d", i);
            fprintf(myfile_txt, "|");
            fprintf(myfile_txt, "%.2lf", start);
            start += delta;
            start++;
            fprintf(myfile_txt, "|");
            fprintf(myfile_txt, "%.3lf", fun(start));
            fprintf(myfile_txt, "|\n");
            i++;
        }
        fprintf(myfile_txt,"+---------+---------+---------+\n");
    }
    else {
        fprintf(myfile_txt, "Group RS-p%.0lf\n", group);
        fprintf(myfile_txt, "Variant %.0lf\n", brigade);
        fprintf(myfile_txt, "x1=%.0lf  x2=%.0lf delta=%.2lf\n", start, end, step);
        head_txt(myfile_txt);
        while (start <= end) {
            fprintf(myfile_txt, "|");
            fprintf(myfile_txt, "%d", i);
            fprintf(myfile_txt, "|");
            fprintf(myfile_txt, "%.2lf", start);
            start += step;
            start++;
            fprintf(myfile_txt, "|");
            fprintf(myfile_txt, "%.3f", fun(start));
            fprintf(myfile_txt, "|\n");
            i++;
        }
        fprintf(myfile_txt,"+---------+---------+---------+\n");
        fclose(myfile_txt);
    }
}

void save_bin(double group, double brigade, double start, double end, double dots, double step) {
    int i = 0;
    double delta;
    FILE *myfile_bin;
    char name_bin[] = ("../result.bin");
    if (dots > 0) {
        myfile_bin = fopen(name_bin, "w");
        printf("Group RS-p%.0lf\n", group);
        printf("Variant %.0lf\n", brigade);
        fprintf(myfile_bin, "x1=%.0lf  x2=%.0lf number of rows=%d\n", start, end, dots);
        head_bin(myfile_bin);
        while (start < end && i < dots) {
            delta = (end - start) / (dots - 1);
            fprintf(myfile_bin, "|");
            fprintf(myfile_bin, "\t%d\t", i);
            fprintf(myfile_bin, "|");
            fprintf(myfile_bin, "\t%.2lf\t", start);
            start += delta;
            start++;
            fprintf(myfile_bin, "|");
            fprintf(myfile_bin, "\t%.2lf\t", fun(start));
            fprintf(myfile_bin, "|\n");
            i++;
        }
        fprintf(myfile_bin, "+-------+-----------+---------------+\n");
        fclose(myfile_bin);
    }
    else {
        myfile_bin = fopen(name_bin, "w");
        fprintf(myfile_bin, "Group RS-p%.0lf\n", group);
        fprintf(myfile_bin, "Variant %.0lf\n", brigade);
        fprintf(myfile_bin, "x1=%.0lf  x2=%.0lf delta =%.2lf\n", start, end, step);
        head_bin(myfile_bin);
        while (start <= end) {
            fprintf(myfile_bin, "|");
            fprintf(myfile_bin, "\t%d\t", i);
            fprintf(myfile_bin, "|");
            fprintf(myfile_bin, "\t%.2lf\t", start);
            start += step;
            start++;
            fprintf(myfile_bin, "|");
            fprintf(myfile_bin, "\t%.3f\t", fun(start));
            fprintf(myfile_bin, "|\n");
            i++;
        }
        fprintf(myfile_bin, "+-------+-----------+---------------+\n");
        fclose(myfile_bin);
    }
}

void output () {
    FILE *myfile;
    int i = 0;
    char group[7];
    double brigade, start, end, dots, step, delta;
    char massive[12];
    myfile = fopen("../input.dat", "r");
    fscanf(myfile, "%s%lf%lf%lf%lf%lf", &group, &brigade, &start, &end, &dots, &step);
    char *estr = fgets(massive, sizeof(massive), myfile);
    save_bin(group, brigade, start, end, dots, step);
    save_txt(group, brigade, start, end, dots, step);
    fclose(myfile);
    if (dots > 0) {
        printf("x1=%.0lf  x2=%.0lf number of rows=%.0lf\n", start, end, dots);
        head();
        while (start < end && i < dots) {
            delta = (end - start) / (dots - 1);
            printf("|");
            printf("\t%d\t", i);
            printf("|");
            printf("\t%.2lf2\t", start);
            start += delta;
            start++;
            printf("|");
            printf("\t%f\t", fun(start));
            printf("|\n");
            i++;
        }
        printf("+-------+-----------+---------------+\n");
    }
    else {
            printf("\n");
            printf("Group RS-p%.0lf\n", group);
            printf("Variant %.0lf\n", brigade);
            printf("x1=%.0lf  x2=%.0lf delta=%.2lf\n", start, end, step);
            head();
            while (start <= end) {
                printf("|");
                printf("\t%d\t", i);
                printf("|");
                printf("\t%.2lf2\t", start);
                start += step;
                start++;
                printf("|");
                printf("\t%f\t", fun(start));
                printf("|\n");
                i++;
            }
            printf("+-------+-----------+---------------+\n");
        }

    }

int main()
{
    FILE *myfile;
    myfile = fopen("../input.dat", "r");
    if (!myfile) {
        printf("\nError!");
        return 0;
    }
    else {
        file_exist ();
    }
    return 0;
}
