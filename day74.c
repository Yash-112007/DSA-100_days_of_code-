#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 1000
#define LEN 100

// comparator for sorting strings
int cmp(const void *a, const void *b)
{
    return strcmp((char *)a, (char *)b);
}

int main()
{
    int n;
    scanf("%d", &n);

    char votes[MAX][LEN];

    // input names
    for(int i = 0; i < n; i++)
        scanf("%s", votes[i]);

    // Step 1: sort names lexicographically
    qsort(votes, n, sizeof(votes[0]), cmp);

    // Step 2: count votes
    char winner[LEN];
    int maxVotes = 1, count = 1;

    for(int i = 1; i < n; i++)
    {
        if(strcmp(votes[i], votes[i-1]) == 0)
            count++;
        else
        {
            if(count > maxVotes)
            {
                maxVotes = count;
                strcpy(winner, votes[i-1]);
            }
            count = 1;
        }
    }

    // last candidate check
    if(count > maxVotes)
    {
        maxVotes = count;
        strcpy(winner, votes[n-1]);
    }

    // output result
    printf("%s %d", winner, maxVotes);

    return 0;
}
