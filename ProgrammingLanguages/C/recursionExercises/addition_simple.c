#include <stdio.h>

int main(void)
{
    int n = 0;
    printf("Which number do you want to add 10? ");
    scanf("%d", &n);
    int x = n + 10;
    printf("the total amount is %d", x);
    return x;
}
