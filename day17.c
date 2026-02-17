#include <stdio.h>

int main()
{
    int n, i;
    
    // size input
    scanf("%d", &n);
    
    int arr[n];
    
    // array input
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    // assume first element is max and min
    int max = arr[0];
    int min = arr[0];
    
    // loop to find max and min
    for(i = 1; i < n; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
        
        if(arr[i] < min)
        {
            min = arr[i];
        }
    }
    
    // output
    printf("Max: %d\n", max);
    printf("Min: %d", min);
    
    return 0;
}
