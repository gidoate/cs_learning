#include <stdio.h>

// Function prototypes
int mergearrays(int n, int array1[], int array2[]);
int mergesort(int n, int array[]);

// Program
int main()
{
    int n = 0;
    printf("Input the array size: ");
    scanf("%d", &n);
    int array1[n];
    int array2[n];
    int n3 = 2*n;
    int array3[n3];
    for (int i = 0; i < n; i++)
    {
        printf("Input element %d of array 1: ", i);
        scanf("%d", &array1[i]);
    }
    for (int i = 0; i < n; i++)
    {
        printf("Input element %d of array 2: ", i);
        scanf("%d", &array2[i]);
    }
    array3[n3] = mergearrays(n, array1, array2);
    mergesort(n3,array3);
}

int mergearrays(int n, int array1[], int array2[])
{
    int n2 = 2*n;
    int arraymerge[n2];
    for (int i = 0; i < n; i++)
    {
        arraymerge[i] = array1[i];
    }
    int x = n;
    for (int i = 0; i < n ; i++)
    {
        arraymerge[x] = array2[i];
        x++;
    }
    return arraymerge[n2];
}

int mergesort(int n, int array[])
{
    int arrayleft[n/2];
    int arrayright[n/2];
    // base case
    if (n == 1)
    {
        return array;
    }
    else
    {
        for (int i = 0; i < n/2; i++)
        {
            int arrayleft[i] = array[i];
        }
        
        int arrayleft[] = array
    }   
}
