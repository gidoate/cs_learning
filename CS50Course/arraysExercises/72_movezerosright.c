#include <stdio.h>

int movezerosright(int n, int array[])
{
    int x = n-1;
    for (int i = n-1; i >= 0; i--)
    {
        if (array[i] == 0 || array[i] == 5)
        {
            int y = array[x];
            array[x] = 0;
            array[i] = y; 
            x--;
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
    movezerosright(10, array);
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", array[i]);
    } 
}