#include "enterastring.h"

bool isWord(const char *str)
{
    for (int i = 0; str[i] != '\0'; i++) 
    {
        if (!isalpha(str[i]))
        {
            return false;
        }
    }
    return true;
}
char* enterastring(int playerNumber)
{
    bool validInput = false;
    static char word[50];
    do
    {
        printf("Player %d, enter a word: ", playerNumber+1);
        scanf("%49s", word); // Limit input to avoid buffer overflow

        if (isWord(word))
        {
            validInput = true;
        } else
        {
            while (getchar() != '\n'); // Discard invalid input
            printf("Invalid input. Please enter a word with letters only.\n");
        }
    } while (!validInput);
    return word;
}