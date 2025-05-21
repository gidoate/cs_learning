#include <stdio.h>

int main(void)
{
    int numbers[2];

    for (int i = 0; i < 2; i++)
    {
        printf("Input number %i: ", i);
        scanf("%i", &numbers[i]);
    }

    int *z1 = &numbers[0];
    printf("z1 points to address %i\n", z1);
    printf("z1 contains value %i\n", *z1);
    int *z2 = &numbers[1];
    printf("z2 points to address %i\n", z2);
    printf("z2 contains value %i\n", *z2);
    int z3 = *z1 + *z2;
    printf("Addition of %i + %i is equal to %i", *z1, *z2, z3);
}