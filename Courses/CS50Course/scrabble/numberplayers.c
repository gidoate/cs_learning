#include "numberplayers.h"

int numberplayers(void)
{
    bool validInput;
    int n;
    do {
        printf("Enter the number of players (up to 10): ");
        validInput = scanf("%d", &n) == 1 && n > 1 && n < 11;
        // Clear the input buffer if the input is invalid
        if (!validInput)
        {
            while (getchar() != '\n'); // Discard invalid input
            printf("Invalid input. Please enter a valid number.\n");
        }
    } while (!validInput);

    return n;
}