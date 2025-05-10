#include <stdio.h>

int main()
{
    int rows;
    printf("Enter the size of a square matrix: ");
    scanf("%d", &rows);
    int columns = rows;
    int matrix[rows][columns];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("Enter elements %i , %i of the matrix: ", i, j);
            scanf("%i", &matrix[i][j]);
        }
    }
    printf("ORIGINAL MATRIX: \n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("%i ", matrix[i][j]);
        }
        printf("\n");
    }
    int sum = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (i == j)
            {
                sum = sum + matrix[i][j];
            }
        }
    }
    printf("The addition of the values in the diagonal is: %i", sum); 
}