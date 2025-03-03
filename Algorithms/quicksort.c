#include <stdio.h>
int swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int array[], int low, int high)
{
    int pivot = array[low];
    int i = low;
    int j = high;
    while (i < j)
    {
        // Looks for the index of the first value higher than pivot starting from the left (i)
        while (array[i] <= pivot && i <= high-1)
        {
            i++;
        }
        // Looks for the index of the frist value lower than pivot starting from the right (j)
        while (array[j] >= pivot && j >= low+1)
        {
            j--;
        }
        // If index from left is lower than index from right, swap values
        if (i < j)
        {
            swap(&array[i], &array[j]);
        }
    }  
    // Swap the pivot to it's correct position in the array
    swap(&array[low], &array[j]);
    return j;
}
int quicksort(int array[], int low, int high)
{
    if (low < high)
    {
        int pivot = partition(array, low, high);
        quicksort(array, low, pivot-1);
        quicksort(array, pivot+1, high);
    }
}
int main(void)
{
    int array[3] = {3, 5, 1};
    int n = sizeof(array) / sizeof(array[0]);
    quicksort(array, 0, n-1);
    for (int i = 0; i < n; i++)
    {
        printf("%i ", array[i]);
    }
}