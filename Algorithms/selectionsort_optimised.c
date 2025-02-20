#include <stdio.h>
// looks for the index at which the max value is and loads the value of that index in the corrsponding index of  
// the sorted array
void selectionsort(int size, int array[])
{
    int temp, maxindex;
    for (int i = 0; i < size; i++)
    {
        maxindex = 0;
        for (int j = 1; j < size - i; j++)
        {
            if (array[j] > array[maxindex])
            {
                maxindex = j;
            }
        }
        temp = array[size - i - 1];
        array[size - i - 1] = array[maxindex];
        array[maxindex] = temp;
    }
}

int main(void)
{
    int numbers[7] = {3, 1, 5, 2, 55, 43, 100};
    selectionsort(7, numbers); 
    
    for (int i = 0; i < 7; i++)
    {
        printf("%i ", numbers[i]);
    }
    return 0;
}