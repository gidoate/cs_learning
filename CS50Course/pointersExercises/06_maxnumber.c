#include <stdio.h>

int main(void)
{
    int numbers[2];
    int *pointers[2];
    int max = 0;

    for (int i = 0; i < 2; i++)
    {
        printf("Input a number: ");
        scanf("%i", &numbers[i]);
    }
    for (int i = 0; i < 2; i++)
    {
        pointers[i] = &numbers[i];
        printf("%p\n", pointers[i]);
    }
    if (*pointers[0] > *pointers[1])
    {
        max = *pointers[0];
        printf("Max number is %i, stored in address %i", *pointers[0], &pointers[0]);
    }
    else
    {
        max = *pointers[1];
        printf("Max number is %i, stored in address %i", *pointers[1], &pointers[1]);
    }

    return 0;    
}