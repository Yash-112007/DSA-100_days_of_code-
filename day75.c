#include <stdio.h>

#define MAX 1000

int maxLenZeroSum(int arr[], int n)
{
    int prefixSum = 0, maxLen = 0;
    
    // hash array to store first index of prefix sums
    int hash[20001];   // range for prefix sum (-10000 to 10000)
    
    // initialize hash with -2 (means not visited)
    for(int i=0; i<20001; i++)
        hash[i] = -2;

    // prefix sum = 0 at index -1
    hash[10000] = -1;

    for(int i=0; i<n; i++)
    {
        prefixSum += arr[i];
        
        int index = prefixSum + 10000; // shift to positive
        
        if(hash[index] != -2)
        {
            int len = i - hash[index];
            if(len > maxLen)
                maxLen = len;
        }
        else
        {
            hash[index] = i;
        }
    }
    
    return maxLen;
}

int main()
{
    int n;
    scanf("%d", &n);
    
    int arr[MAX];
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    
    int result = maxLenZeroSum(arr, n);
    printf("%d", result);
    
    return 0;
}
