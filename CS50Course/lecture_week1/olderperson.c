#include <stdio.h>

int main(void)
{
    char firstname[50];
    char secondname[50];
    int firstage;
    int secondage;

    printf("What's the first person's name? ");
    scanf("%s", &firstname);
    printf("Hello, %s, what's your age? ", firstname);   
    scanf("%d", &firstage);

    printf("What's the second person's name? ");
    scanf("%s", &secondname);
    printf("hello, %s, what's your age? ", secondname);   
    scanf("%d", &secondage);

    if (firstage > secondage)
    {
    printf("%s is older!", firstname);
    } 
    else if (firstage < secondage)
    {
    printf("%s is older!", secondname);
    }
    else {
    printf("You are both the same age!");
    }   
}