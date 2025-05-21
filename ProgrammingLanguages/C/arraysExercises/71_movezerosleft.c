#include <stdio.h>

int movezerosleft(int n, int array[])
{
    int x = 0;
    for (int i = 0; i < n; i++)
    {
        if (array[i] == 0)
        {
            int y = array[x];
            array[x] = array[i];
            array[i] = y; 
            x++;
        }
    }
    return array[n];    
}

int main()
{
    int array[10];
    int arrayzeros[10];
    for (size_t i = 0; i < 10; i++)
    {
        printf("Input element %d of your array of 10 values: ", i);
        scanf("%d", &array[i]);
    }
    movezerosleft(10, array);
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", array[i]);
    } 
}