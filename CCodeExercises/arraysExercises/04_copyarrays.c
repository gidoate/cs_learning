#include <stdio.h>

int getarray(int x, int n, int array[])
{
    // base case
    if (x == n)
    {
        return array[n];
    }
    else
    {
        printf("Element %d: ", x+1);
        scanf("%d", &array[x]);
        return getarray(x+1, n, array);
    }
}

int main()
{
    int x = 0;
    int n = 0;
    printf("Input the number of elements to be stored in the array : ");
    scanf("%d", &n);
    int originalnumbers[n];
    int copynumbers[n];
    originalnumbers[n] = getarray(x, n, originalnumbers);
    for (int i = 0; i < n; i++)
    {
        copynumbers[i]=originalnumbers[i];
    }
    
    printf("The elements in input array are: ");
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", originalnumbers[i]);
    }
    printf("\nThe elements in output array are: ");
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", copynumbers[i]);
    }
    
    return 0;
}
