#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *word = malloc(100 * sizeof(char)); // Allocate memory for the word
    if (word == NULL)
    {
        printf("Error");
        return 1;
    }
    printf("write your word: ");
    scanf("%99s", word);
    printf("%s\n", word);
    printf("%p\n", (void *)word);
    return 0;
}