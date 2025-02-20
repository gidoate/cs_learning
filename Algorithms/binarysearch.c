#include <stdio.h>

int binarysearch(int array[], int left, int right, int ninput)
{
    if (right >= left)
    {
        int mid = left + (right - left) / 2;
        printf("Current middle index: %i\n", mid);

        // Base case 1 - the input number is in the list
        if (array[mid] == ninput)
        {
            printf("The number is in the list\n");
            return mid;
        }

        // Base case 2 - the input number is not in the list (cannot continue dividing the array in two halves)
        if (left == right)
        {
            printf("The number is not in the list\n");
            return -1;
        }

        // Right part of the array
        if (array[mid] < ninput)
        {
            printf("We are in the right\n");
            return binarysearch(array, mid + 1, right, ninput);
        }

        // Left part of the array
        printf("We are in the left\n");
        return binarysearch(array, left, mid - 1, ninput);
    }

    printf("The number is not in the list\n");
    return -1;
}

int main()
{
    int array[] = {2, 3, 4, 10, 40};
    int n = sizeof(array) / sizeof(array[0]);
    int ninput = 0;
    printf("Enter the number to search: ");
    scanf("%i", &ninput);
    int result = binarysearch(array, 0, n - 1, ninput);
    if (result != -1)
    {
        printf("Element is present at index %d\n", result);
    } else
    {
        printf("Element is not present in array\n");
    }
    return 0;
}