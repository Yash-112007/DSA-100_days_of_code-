#include <stdio.h>

int main()
{
    int n;

    // Input size
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Input array
    printf("Enter %d sorted elements:\n", n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Unique elements are:\n");

    // Always print first element
    printf("%d ", arr[0]);

    // Print only when current != previous
    for(int i = 1; i < n; i++)
    {
        if(arr[i] != arr[i - 1])
        {
            printf("%d ", arr[i]);
        }
    }

    return 0;
}
