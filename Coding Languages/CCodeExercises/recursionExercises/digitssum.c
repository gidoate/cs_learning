#include <stdio.h>

int digitssum(int n, int addition)
{
    if (n == 0)
    {
        return addition;
    }
    else
    {
        addition = addition + n%10;
        return digitssum(n/10, addition);
    }
}
int main()
{   
    int n;
    int init = 0;
    printf("Type number: ");
    scanf("%d", &n);
    int addition = digitssum(n, init);
    printf("Digits add up to: %d", addition);

    return 0;
}
