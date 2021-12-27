int head_bin (FILE *myfile_bin) {
    fprintf(myfile_bin, "++++++++++++++++++++++++++++++++++++++++\n");
    fprintf(myfile_bin, "+     N    +     X     +      F(X)     +\n");
    fprintf(myfile_bin, "++++++++++++++++++++++++++++++++++++++++\n");
    fprintf(myfile_bin, "+----------+-----------+---------------+\n");
}

int head_txt (FILE *myfile_txt) {
    fprintf(myfile_txt, "+++++++++++++++++++++++\n");
    fprintf(myfile_txt, "+   N  +  X   +  F(X) +\n");
    fprintf(myfile_txt, "+++++++++++++++++++++++\n");
    fprintf(myfile_txt, "+---------------------+\n");
}

int head()
{
    printf("++++++++++++++++++++++++++++++++++++++++\n");
    printf("+   N      +     X     +       F(X)    +\n");
    printf("++++++++++++++++++++++++++++++++++++++++\n");
    printf("+----------+-----------+---------------+\n");
}

void create () {
    FILE *myfile;
    int i;
    double ar;
    myfile = fopen("../input.dat", "w");
    for (i=0; i < 6; i++) {
        printf("\nEnter values %d\t", i);
        scanf("%lf", &ar);
        fprintf(myfile, "%.2lf\n", ar);
    }
    fclose(myfile);
    output();
}

void file_exist () {
    unsigned int choice;
    printf("\nFile already exists. Re-create?");
    printf("\n1 - Yes \t 2 - No\n");
    scanf("%u", &choice);
    switch (choice) {
        case 1:
            create();
            break;
        case 2:
            output();
            break;
    }
}
