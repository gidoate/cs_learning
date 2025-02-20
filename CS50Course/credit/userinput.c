#include "userinput.h"

unsigned long long userinput(void)
{
    bool validInput;
    unsigned long long n=0;
    do {
        printf("Enter your credit card number (13 to 16 digits): ");
        validInput = scanf("%llu", &n) == 1 && n > 999999999999 && n <= 9999999999999999;
        // Clear the input buffer if the input is invalid
        if (!validInput)
        {
            while (getchar() != '\n'); // Discard invalid input
            printf("Invalid input. Please enter a valid number.\n");
        }
    } while (!validInput);

    return n;
}