#include <stdio.h>

int getarray(int n, int numbers[])
{
    // base case
    if (n == 0)
    {
        printf("Element %d: ", n);
        scanf("%d", &numbers[n]);
        return 0;
    }
    // recursive case
    else
    {
        printf("Elment %d: ", n);
        scanf("%d", &numbers[n]);
        getarray(n-1, numbers);
    }
    return numbers[n];   
}

int printnum(int n, int numbers[])
{
    // base case
    if (n == 0)
    {
        printf("%d", numbers[n]);
        return 0;
    }
    // recursive case
    else
    {
        printf("%d ", numbers[n]);
        printnum(n-1, numbers);
    }
    return 0;    
}

int main(void)
{
    int n = 0; // number of items in the array
    int x = 0;
    printf("Number of items in the array: ");
    scanf("%d", &n);
    int numbers[n];
    getarray(n-1, numbers);
    printnum(n-1, numbers);

    return 0;
}