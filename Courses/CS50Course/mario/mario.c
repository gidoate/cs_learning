#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int n;
    bool validInput;

    do {
        printf("How many rows shall the pyramid have? Please use a positive number: ");
        validInput = scanf("%d", &n) == 1 && n > 0;
        // Clear the input buffer if the input is invalid
            if (!validInput)
            {
              while (getchar() != '\n'); // Discard invalid input
              printf("Invalid input. Please enter a positive number.\n");
            }
        } while (!validInput);

    for (int i = 0; i < n; i++)
    {
        for (int j=0; j < 2*n+2; j++)
        {
            if (i+j<n-1 || j==n || j==n+1)
            {
                printf(" ");
            }
            else if (j-i<n+3)
            {
                 printf("#");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    } 
}