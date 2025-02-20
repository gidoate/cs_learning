// This implementation I did uses an additional array (arraysorted) because my understanding of this algorithm was that
// it was required to use an additional array (according to lectures I followed)
// Optimised version of the algorithm does not require an additional array as it uses the indexes in a different way
#include <stdio.h>
int selectionsort(int size, int array[]);

int selectionsort(int size, int array[])
{
    int arraysorted[size];
    int temp = 0;
    int maxindex = 0;
    // search for max value in the array
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (temp <= array[j])
            {
                temp = array[j];
                maxindex = j;   
            }  
        }
        arraysorted[size-i-1] = temp;
        array[maxindex] = 0;
        temp = 0;      
    }
    for (int i = 0; i < size; i++)
    {
        array[i] = arraysorted[i];
    }
    return array[size];
}

int main(void)
{
    int numbers[7] = {3, 1, 5, 2, 55, 43, 100};
    printf("Unsorted array is: \n");
    for (int i = 0; i < 7; i++)
    {
        printf("%i ", numbers[i]);
    }
    printf("\n");
    selectionsort(7, numbers); 
    
    printf("Sorted array is: \n");
    for (int i = 0; i < 7; i++)
    {
        printf("%i ", numbers[i]);
    }
    return 0;
}
