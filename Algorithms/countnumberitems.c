#include <stdio.h>

int countitems(int n, int array [])
{
    if (n == 1)
    {
        return 1;
    }
    else
    {
        n--;
        return 1+countitems(n, array);
    }
}
int maxvalue(int n, int array[])
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return array[0];
    }
    else
    {
        printf("we are here\n");
        int max_in_rest = maxvalue(n-1, array);
        if (array[n - 1] > max_in_rest)
        {
            return array[n - 1];
        } 
        else
        {
            return max_in_rest;
        }
    }    
}
int main(void)
{
    int array[4] = {1, 2, 17, 4};
    int items = countitems(4, array);
    printf("The number of items is %i\n", items);
    int max = maxvalue(4, array);
    printf("The max value is %i\n", max);

}