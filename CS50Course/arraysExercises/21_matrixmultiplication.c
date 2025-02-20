#include <stdio.h>

int main()
{
    int nrow1;
    int ncol1;
    int nrow2;
    int ncol2;
    printf("Reminder - number of columns1 and number of rows1 shall be equal (ie. 4x3 , 3x5)\n");
    printf("Enter the number of rows of matrix 1 [nrow1]: ");
    scanf("%i", &nrow1);
    printf("Enter the number of columns of matrix 1 [ncol1]: ");
    scanf("%i", &ncol1);
    printf("Enter the number of rows of matrix 2 [nrow2]: ");
    scanf("%i", &nrow2);
    printf("Enter the number of columns of matrix 2 [ncol2]: ");
    scanf("%i", &ncol2);
    int matrix1[nrow1][ncol1];
    int matrix2[nrow2][ncol2];
    int matrix3[nrow1][ncol2];

    for (int i = 0; i < nrow1; i++)
    {
        for (int j = 0; j < ncol1; j++)
        {
            printf("Input the element of row %i and column %i of matrix 1: ", i, j);
            scanf("%i", &matrix1[i][j]);
        }
    }
    for (int i = 0; i < nrow2; i++)
    {
        for (int j = 0; j < ncol2; j++)
        {
            printf("Input the element of row %i and column %i of matrix 2: ", i, j);
            scanf("%i", &matrix2[i][j]);
        }
    }
    printf("MATRIX1: \n");
    for (int i = 0; i < nrow1 ; i++)
    {
        for (int j = 0; j < ncol1; j++)
        {
            printf("%d ", matrix1[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("MATRIX2: \n");
    for (int i = 0; i < nrow2 ; i++)
    {
        for (int j = 0; j < ncol2; j++)
        {
            printf("%d ", matrix2[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    for (int i = 0; i < nrow1; i++) // row first matrix
    {
        for (int j = 0; j < ncol2; j++) // column second matrix
        {
            int sum = 0;
            for (int k = 0; k < ncol1; k++)
            {
                sum =  sum + matrix1[i][k]*matrix2[k][j];
            }
            matrix3[i][j] = sum;
        }
    }
    printf("MATRIX3: \n");
    for (int i = 0; i < nrow1 ; i++)
    {
        for (int j = 0; j < ncol2; j++)
        {
            printf("%d ", matrix3[i][j]);
        }
        printf("\n");
    }       
}    