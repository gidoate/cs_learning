#include <stdio.h>

int naturalnumbers(int n, int x)
{
    if (x == n)
    {
        printf("%d ", n);
        return 0;
    }
    else
    {
        printf("%d ", x);
        naturalnumbers(n, x+1);
    }
}

int main(void)
{
    int n = 100;
    int x = 1;
    naturalnumbers(n, x);
}