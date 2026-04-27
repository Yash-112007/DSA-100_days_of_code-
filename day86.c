#include <stdio.h>

int main() {
    long long n;
    scanf("%lld", &n);

    long long low = 0, high = n;
    long long ans = 0;

    while (low <= high) {
        long long mid = (low + high) / 2;
        long long sq = mid * mid;

        if (sq == n) {
            ans = mid;
            break;
        }
        else if (sq < n) {
            ans = mid;      // possible answer
            low = mid + 1;  // search right
        }
        else {
            high = mid - 1; // search left
        }
    }

    printf("%lld", ans);
    return 0;
}
