#include <stdio.h>

int main(void)
{
    int m = 0;
    printf("Input a number: ");
    scanf("%i", &m);
    int *z = &m; // Assigns the address of 'm' to 'z'
    printf("'z' stores the address of 'm': %p\n",z);
    printf("'*z' stores the value of 'm': %i\n",*z);
    printf("'&m' stores the address of 'm': %p\n", &m);
    return 0;
}