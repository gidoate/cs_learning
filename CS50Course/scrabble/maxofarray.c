#include "maxofarray.h"

int maxofarray(int array[],int arraysize)
{
    int indexmax = 0;
    for (int i = 0; i < arraysize; i++)
    {
        if (array[i] > array[i-1])
        {
            indexmax = i;
        }
    }
    return indexmax;
}