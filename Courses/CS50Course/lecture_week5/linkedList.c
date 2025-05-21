#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number; // Data of the node
    struct node *next; // Pointer to the next node in the list
}node;

int get_int(char *prompt) // Function prototype for get_int
{
    int number; // Variable to store the integer input
    printf("%s", prompt);
    scanf("%i", &number); // Read an integer from the user
    return number; // Return the integer value
} 

int main(void)
{
    node *list = NULL; // Pointer to the first item of the list

    for (int i = 0; i < 3; i++)
    {
        node *n = malloc(sizeof(node)); // Pointer to the first item of allocated memory for a new node (whatever the size of a node is). n points to a new node
        if (n == NULL) // Check if the memory allocation was successful
        {
            fprintf(stderr, "Memory allocation failed\n");
            return 1;
        }
        n->number = get_int("Enter a number: "); // Assign a value to the node - the operatotr *n.number could be swapped by n->number (get_int won't work, is part of CS50 library)
        n->next = list; // Point the new node to the old list. From here onwards, -> is used to access the next node in the list
        list = n;                                                                         
    }
    
    node *ptr = list; // Pointer to traverse the list
    while (ptr != NULL)
    {
        printf("%i\n", ptr->number); // Print the number in the current node
        ptr = ptr->next; // Move to the next node in the list
    }
    
    
}