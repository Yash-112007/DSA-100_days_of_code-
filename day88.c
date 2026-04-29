#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// check if cows can be placed with at least 'dist' gap
int canPlaceCows(int stalls[], int n, int k, int dist) {
    int cowsPlaced = 1;
    int lastPos = stalls[0];

    for(int i = 1; i < n; i++) {
        if(stalls[i] - lastPos >= dist) {
            cowsPlaced++;
            lastPos = stalls[i];
        }
        if(cowsPlaced >= k)
            return 1;
    }
    return 0;
}

int aggressiveCows(int stalls[], int n, int k) {
    qsort(stalls, n, sizeof(int), compare);

    int low = 1;
    int high = stalls[n-1] - stalls[0];
    int ans = 0;

    while(low <= high) {
        int mid = (low + high) / 2;

        if(canPlaceCows(stalls, n, k, mid)) {
            ans = mid;        // possible → try bigger distance
            low = mid + 1;
        } else {
            high = mid - 1;   // not possible → reduce distance
        }
    }
    return ans;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int stalls[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &stalls[i]);

    printf("%d", aggressiveCows(stalls, n, k));
    return 0;
}
