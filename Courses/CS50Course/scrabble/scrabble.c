#include <stdio.h>
#include <stdbool.h>
#include "alltocapital.h"
#include "enterastring.h"
#include "maxofarray.h"
#include "numberplayers.h"
// Max number of characters per word
const int N=50; 

// Array of points for each letter
// A B C D E F G H I J K L M N O P Q  R S T U V W X Y Z
// 1 3 3 2 1 4 2 4 1 8 5 1 3 1 1 3 10 1 1 1 1 4 4 8 4 10
const int points [] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int main (void)
{
    // Number of players
    int n = numberplayers();
    int count[n];

    // Word input and points evaluation
    for (int i = 0; i < n; i++)
    {
        int j=0;
        count[i]=0;
        char* word = enterastring(i);

        // Conversion to all capital letters
        alltocapital(word);
    
        // Evaluation loop
        while (word[j]!='\0')
        {
            int position = word[j]-65;
            int pointstoadd = points[position];
            count[i] = count[i] + pointstoadd;
            j++;    
        }   
    }
    
    // Winner calculation 
    int winner = maxofarray(count, n) + 1;
     printf("Winner is Player %d \n", winner);
}