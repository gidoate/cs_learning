#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "numberofvoters.h"
#include "vote.h"

int main(int argc, char *argv[])
{ 
    // Input check
    if (argc < 2)
    {
        printf("Usage: plurality [candidate...]\n");
        return 1; // Insufficient arguments
    }
    // Array of candidates
    int ncandidates = argc;
    char *candidates[ncandidates];
    for (int i = 0; i < ncandidates; i++)
    {
        candidates[i] = argv[i];   
    }

    // Number of voters
    int nvoters = numberofvoters();

    // VOTES INPUT - Array of votes
    // Allocates memory for 'n' candidates
    char* votes[ncandidates];
    for (int i = 0; i < nvoters; i++)
    {
        // Allocate memory for each vote, assuming each vote can be up to 99 characters long
        votes[i] = malloc(100 * sizeof(char));
        if (votes[i] == NULL)
        {
            printf("Memory allocation failed\n");
            return 1;
        }
        printf("Vote: ");
        scanf("%s", votes[i]);
    }


    // VOTES COUNT
    // Counter for each candidate
    int counter[ncandidates]; 
    for (int i = 0; i < ncandidates; i++)
    {
        counter[i] = 0;
    }
    // Loop to evaluate current candidate amount of votes
    for (int i = 0; i < ncandidates; i++)
    {
        for (int j = 0; j < nvoters; j++)
        {
            if (strcmp(candidates[i], votes[j])==0) // strcmp to compare strings
            {   
                counter[i]++;
            } 
        }
    }
    int max=0;
    int max_index=0;
    for (int i = 1; i < ncandidates; i++)
    {
        if (counter[i] >= max)
        {
            max = counter[i];
            max_index = i;
            printf("%s \n", candidates[max_index]);
        }
    }   
    printf("Max votes received is %d\n", max);
}