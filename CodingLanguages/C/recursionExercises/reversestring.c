#include <stdio.h>

char reversestring(int x, int n, char word[])
{
    // base case
    if (n == 0)
    {
        return word[n];
    }
    // recursion case
    else
    {
        word[n] = word[x];
        x++;
        reversestring(x, n-1, word);
    }
}
int main()
{
    int x = 0;
    int n = 0;
    char word[];
    printf("Write your word: ");
    int i = 0;
    while (word[i] != "\0")
    {
        word[i]
    }
    
    
    scanf("s%",wor)
}