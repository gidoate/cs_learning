#include <stdio.h>

int main()
{
    int rows = 0;
    int columns = 0;
    printf("Enter the number of rows: ");
    scanf("%i", &rows);
    printf("Enter the number of columns: ");
    scanf("%i", &columns);

    int matrix[rows][columns]; // Remember to declare after values from user are introduced
    int matrixtrans[columns][rows];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("Enter elements %i , %i of the matrix: ", i, j);
            scanf("%i", &matrix[i][j]);
        }
    }
    for (int i = 0; i < columns; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            matrixtrans[i][j] = matrix[j][i];
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
    printf("TRANSPOSED MATRIX: \n");
    for (int i = 0; i < columns; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            printf("%i ", matrixtrans[i][j]);
        }
        printf("\n");
    }
    
      
}