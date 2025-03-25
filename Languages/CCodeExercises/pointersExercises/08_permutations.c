// Not completed

#include <stdio.h>
#include <string.h>

unsigned long long factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}

int permutations(char *string)
{
    int characters = strlen(string);
    int permutations = factorial(characters);
    

    return 0;
}

int main(void)
{
    char string[] = "abc";
    permutations(string);
    return 0;
}