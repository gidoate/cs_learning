/*
This code increases the amount of items in a list by 1
It uses Realloc, which is not much more efficient than the original idea
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
    
    int *tmp = realloc(list, 4*sizeof(int)); // Realloc takes two arguments: the variable that should be reallocated and the chunk of memory that need to be allocated
    if (tmp == NULL)
    {
        free(list); // Free the old list if realloc fails
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
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