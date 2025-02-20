#include <stdio.h>

int main(void)
{
    char myName[50];
    printf("What's your name? ");
    scanf("%s", &myName);
    printf("hello, %s \n", myName);   
}