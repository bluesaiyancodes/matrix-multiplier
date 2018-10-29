#include <stdio.h>
#include <conio.h>
#include <math.h>

//Global vars
int matrix1[25][25], matrix2[25][25], result[25][25];
int r1, c1, r2, c2, i, j, k; //throughout the program i and j are variables reserved for use in for loops

int initSetup()
{	//this is the initial set up asking the values from user
	printf("Enter the no. of rows in the first matrix and press the return key then proceed to enter the no. of coloumns \n");
	scanf("%d", &r1);
	printf("x\n");
	scanf("%d", &c1);

	printf("Enter the no. of rows in the second matrix and press the return key then proceed to enter the no. of coloumns \n");
	scanf("%d", &r2);
	printf("x\n");
	scanf("%d", &c2);
}

int handleErr()
{	//When matrices cannot be multiplied
	printf("Error! the matrices cannot be multiplied\n\nEnter new values\n");
	initSetup();
}

//error checking
int checkForErr()
{
	if (c1 != r2)
	{
		return true;
	}
}

//Get values inside the matrix from user
getValues()
{
	printf("\nEnter elements a[i][j] of the first matrix(%dx%d)\n", r1, c1);
	for(i = 1; i <= r1; i++)
	{
		for(j = 1; j <= c1; j++)
		{
			// taking a[i][j] as general element of Ist matrix
			printf("Element a[%d][%d]= ", i, j);
			scanf("%d",&matrix1[i][j]);
		}
	}

	printf("\nEnter elements b[i][j] of the second matrix(%dx%d)\n", r2, c2);
	for(i = 1; i <= r2; i++)
	{
		for(j = 1; j <= c2; j++)
		{
			// taking b[i][j] as general element of IInd matrix
			printf("Element b[%d][%d]= ", i, j);
			scanf("%d",&matrix2[i][j]);
		}
	}
}

//Heres where the real magic happens.
multiplyMatrices()
{
    int sum=0;
    for(i=1;i<=r1;i++){
        for(j=1;j<=c2;j++){
            for(k=1;k<=r2;k++){
                sum+=matrix1[i][k]*matrix2[k][j];
            }
            result[i][j]=sum;
            sum=0;
        }
    }
}

//Print Result
printResult()
{
	for(i = 1; i <= c1; i++)
	{
		for(j = 1; j <= c2; j++)
		{
			printf("%d\t", result[i][j]);
		}
		printf("\n");
	}
}


//Main program that binds everything
int main()
{
	initSetup();

	if (checkForErr() == true)
	{
		handleErr();
	};

	getValues();

	multiplyMatrices();

	printResult();

	return 0;
}
