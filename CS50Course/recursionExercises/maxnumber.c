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

int maxnumber(int n, int numbers[], int max)
{
    // base case
    if (n == 0)
    {
        printf("Max number is %d", max);
        return 0;
    }
    // recursive case
    else
    {
        if (max < numbers[n])
        {
            max = numbers[n];
        }
        n = n-1;
        maxnumber(n, numbers, max);
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
    int max=0;
    getarray(n-1, numbers);
    maxnumber(n-1, numbers, max);

    return 0;
}