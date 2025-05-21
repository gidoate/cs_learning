#include <stdio.h>
#include <stdbool.h>

#define MAX_CANDIDATES 9
#define MAX_NAMELENGTH 15
#define MAX_RANKS 3
#define MAX_VOTERS 100

typedef struct
{
    char* name[MAX_CANDIDATES]; // Max number of candidates is 100
    int votes[MAX_CANDIDATES];
    bool eliminated[MAX_CANDIDATES];
} candidate;

typedef struct 
{
    int voter[MAX_VOTERS];
    char* rank[MAX_RANKS];
}voter;


int main(int argc, char *argv[])
{ 
    // Input check
    if (argc < 2)
    {
        printf("Please, input a correct amount of candidates\n");
        return 1; // Insufficient arguments
    }

    // Candidate structure initialization
    candidate candidates;
    for (int i = 0; i < argc; i++)
    {
        candidates.name[i] = argv[i];
        candidates.votes[i] = 0;
        candidates.eliminated[i]=0;
    }

    // Number of voters
    int n = 0;
    printf("Number of voters: ");
    scanf("%d", &n);

    // Voters structure creation
    voter voters[n];
    for (int i = 0; i < n; i++)
    {
        printf("Voter %d \n",i+1);
        for (int j = 0; j < MAX_RANKS; j++)
        {
            printf("Rank %d: ", j+1);
            scanf("%s", voters[i].rank[j]);
            printf("%d\n", j);
        }
    }
    return 0;
}
