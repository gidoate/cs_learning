#include <stdio.h>

/* int mathops(int n1, char array[])
{
    
} */

int main()
{
    char array[18];
    int numbers[3]; // Array to store the three numbers
    int n = 0;
    int i = 0;
    int numIndex = 0;
    int temp = 0;
    printf("Enter 3 numbers separated by commas (max digits 5): ");
    scanf("%s", array);
    while (array[i] != '\0')
    {
        if (array[i] >= '0' && array[i] <= '9')
        {
            temp = temp * 10 + (array[i] - '0'); // Build the number
        } 
        else if (array[i] == ',')
        {
            numbers[numIndex++] = temp; // Store the number in the array
            temp = 0; // Reset the temporary variable
        }
        i++;
        n++;
    }
    numbers[numIndex] = temp; // Store the last number

    // Print the numbers to verify
    for (int j = 0; j < 3; j++) {
        printf("Number %d: %d\n", j + 1, numbers[j]);
    }
    


    //mathops(n, array);
}