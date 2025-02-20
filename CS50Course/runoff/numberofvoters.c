#include "numberofvoters.h"

int numberofvoters(void)
{
    int n = 0;
    bool validInput;
    do
    {
        printf("Number of voters: ");
        validInput = scanf("%d", &n) == 1 && n > 0;

        // Clear the input buffer if the input is invalid
        if (!validInput)
        {
            while (getchar() != '\n'); // Discard invalid input
            printf("Invalid input. Please enter a positive number.\n");
        }
    } while (!validInput);

    return n;
}