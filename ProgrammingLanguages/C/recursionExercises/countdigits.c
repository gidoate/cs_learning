#include <stdio.h>

int countdigits(int n, int count)
{
    if (n/10 == 0)
    {
        count = count + 1;
        return count;
    }
    else
    {
        count = count + 1;
        countdigits(n/10, count);
    }
}
int main(void)
{
    int n;
    int count=0;
    printf("Enter a number you want to know the number of digits: ");
    scanf("%d", &n);
    printf("%d", countdigits(n, count));

    return 0;
}
