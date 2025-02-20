#include <stdio.h>

int main(void)
{
    int numbers[3];

    for (int i = 0; i < 2; i++)
    {
        printf("Input number %i: ", i);
        scanf("%i", &numbers[i]);
    }
    for (int i = 0; i < 2; i++)
    {
        printf("number %i is in address %d\n", i, &numbers[i]);
        printf("number %i value is %i\n", i, numbers[i]);
    }
    numbers[2] = numbers[0] + numbers[1];

    printf("Addition of %i + %i is equal to %i, and it's stored in address %d", numbers[0], numbers[1], numbers[2], &numbers[2]);
}