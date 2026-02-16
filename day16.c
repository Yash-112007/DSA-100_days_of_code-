#include <stdio.h>

int main()
{
    int n;

    // input size
    printf("Enter size: ");
    scanf("%d", &n);

    int arr[n];

    // input array
    printf("Enter elements: ");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // frequency count
    for(int i = 0; i < n; i++)
    {
        int count = 1;

        // check if already counted
        if(arr[i] == -1)
            continue;

        for(int j = i + 1; j < n; j++)
        {
            if(arr[i] == arr[j])
            {
                count++;
                arr[j] = -1; // mark as counted
            }
        }

        printf("%d:%d ", arr[i], count);
    }

    return 0;
}
