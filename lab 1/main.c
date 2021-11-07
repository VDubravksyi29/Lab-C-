#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <stdbool.h>
#include <stdlib.h>


int checkLenght(float a)
{
	int n = 0;
	int temp;
	if (a < 0)
		n++;
	for (;;)
	{
		temp = a;
		if (temp == 0)
			return n;
		a /= 10;
		n++;
	}
}

double func(float x)
{
	return pow(x,3)*sin(6*x);
}

void paintTable(float x1, float x2, float delta, unsigned int n)
{
	int iLenght, XLenght, funcLenght;
	int i = 1;
	float X = x1;
	for (; i < n; i++)
	{
		iLenght = checkLenght(i);
		XLenght = checkLenght(X);
		funcLenght = checkLenght(func(X));
		printf("+---------+---------+---------+\n");
		printf("|");
		for (int j = 0; j < 9 - iLenght; j++)
		{
			printf(" ");
		}
		printf("%d|", i);

		for (int j = 0; j < 6- XLenght; j++)
		{
			printf(" ");
		}
		printf("%.2f|", X);
		for (int j = 0; j < 5 - funcLenght; j++)
		{
			printf(" ");
		}
		printf("%.3f|", func(X));
		printf("\n");
		X += delta;
		if (i % 10 == 0)
		{
			 printf("Press any key\r");
                    getch();
		}
	}
	printf("+---------+---------+---------+\n");
}
void Menu()
{
	printf("*******************************\n");
	printf("*     N   *    X    *   F(X)  *\n");
	printf("*******************************\n");
}
int main()
{
	unsigned int variant;
    int N;
    int n;
	float x1, x2, delta, temp;

printf("First variant: X1 X2 N \n");
    printf("Second variant: X1 X2 delta \n");
    printf("Variant: ");
    scanf("%u", &variant);

   while( variant !=1  &&  variant !=2){
        printf("ERROR. Invalid data\n");
        printf("Enter variant (1 or 2): ");
        scanf("%u", &variant);
    }

	switch (variant)
	{
	case 1:
		printf("X1: ");
		scanf_s("%f", &x1);
		printf("X2: ");
		scanf_s("%f", &x2);
		printf("N: ");
		scanf_s("%d", &n);
		delta = (x2 - x1)/(n - 1);
		printf("x1=%.3f  x2=%.3f number points=%d\n", x1, x2, n);
		n++;
		break;

	case 2:
		printf("X1 :");
		scanf_s("%f", &x1);
		printf("X2 :");
		scanf_s("%f", &x2);
		printf("delta :");
		scanf_s("%f", &delta);
		n = 2;
		temp = x1;
		for (;;)
		{
			temp += delta;
			if (temp >= x2)
				break;
			n++;
		}
		printf("x1=%.3f  x2=%.3f delta=%.3f\n", x1, x2, delta);
		break;
	}
	Menu();
	paintTable(x1, x2, delta, n);

	return 0;
}
