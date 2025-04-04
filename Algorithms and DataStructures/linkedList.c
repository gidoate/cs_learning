// This is my version of a linked list for learning purposes.
// As a more advanced version, the linked list code shall have:
//      1. Structure definition
//      2. Create node function
//      3. Insert node function
//      4. Delete node function
//      5. Traverse list function
//      6. Main function

#include <stdio.h>

typedef struct item
{
    char item_name[50];
    int age;
    struct item *next_item;
} item;

int main(void)
{
    item items[3] = {0}; // Initialize the array

    for (int i = 0; i < 3; i++) // Get inputs
    {
        printf("Item %i: ", i+1);
        scanf("%s", items[i].item_name);
        printf("Age %i: ", i+1);
        scanf("%i", &items[i].age);
    }

    for (int i = 0; i < 2; i++) // Link only the first two items
    { 
        items[i].next_item = &items[i+1];
    }
    items[2].next_item = NULL; // Last item points to NULL

    for (int i = 0; i < 3; i++)
    {
        printf("Item Name: %s, Age: %i, Next Item: %p\n", items[i].item_name, items[i].age, (void*)items[i].next_item);
        printf("Current item address: %p\n", &items[i]);
    }

    return 0;
}