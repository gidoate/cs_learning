#include <stdio.h>

int main(void)
{
    int m = 0;
    printf("Input a number: ");
    scanf("%i", &m);
    int *z = &m; // pointer to address of m
    printf("address of m is %i\n", z);
    printf("value of m is %i\n", *z);
    int *ab = &m; // ab assigned with the address of m
    printf("Input a new number: ");
    scanf("%i", &m);
    printf("'m' now is : %i\n", m);
    printf("'ab' points to address: %i\n", ab);
    printf("'ab' holds the value: %i\n", *ab);

}