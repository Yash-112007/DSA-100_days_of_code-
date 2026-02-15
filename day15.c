#include <stdio.h>

int main() {
    int m, n, i, j;
    int matrix[100][100];
    int sum = 0;

    // Input rows and columns
    scanf("%d %d", &m, &n);

    // Input matrix elements
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Calculate primary diagonal sum
    for(i = 0; i < m && i < n; i++) {
        sum = sum + matrix[i][i];
    }

    // Print result
    printf("%d", sum);

    return 0;
}
