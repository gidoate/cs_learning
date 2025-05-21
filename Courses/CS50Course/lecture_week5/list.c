/*
This code increases the amount of items in a list by 1
It's an inefficient code because it uses >40 lines of code to do it
There shall be a better way to do it
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *list = malloc(3*sizeof(int)); // Allocate memory for 3 integers with the size of whatever int is in the computer I am running on
    if(list == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    list[0] = 1; // Assign values to the list
    list[1] = 2; // Assign values to the list
    list[2] = 3; // Assign values to the list

    // Time passes and now I want to add a new number to the list
    // Below a way to do it:
    
    int *tmp = malloc(4*sizeof(int)); // Allocate memory for 4 integers
    if (tmp == NULL)
    {
        free(list); // Free the old list if malloc fails
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    
    for (int i = 0; i < 3; i++)
    {
        tmp[i] = list[i]; // Copy the old values to the new list
    }

    tmp[3] = 4; // Assign the new value to the new list

    free(list); // Free the old list

    list = tmp; // Point the list to the new list
    for (int i = 0; i < 4; i++)
    {
        printf("%i ", list[i]); // Print the list values
    }
    
    // Free the list
    free(list);
    
    return 0;
}