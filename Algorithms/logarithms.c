// This is logarithm calculator only for integer numbers
// Could be generalised for floating point numbers, but for the moment I leave it like this
#include <stdio.h>

int main(void)
{
    int number = 0;
    int base = 0;
    printf("Please enter a number: ");
    scanf("%i", &number);
    printf("Please enter the logarithm base: ");
    scanf("%i", &base);

    int count = 0;
    int reduced = number; // this is the number that will keep on reducing (dividing) in the loop
    // log base 2 of number
    while (reduced > 1)
    {
        reduced = reduced/base;
        count++;
    }
    printf("The logarithm base %i of %i is %i", base, number, count);
}