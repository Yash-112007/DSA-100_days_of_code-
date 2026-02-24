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


    int k;

    // input rotation
    printf("Enter k: ");
    scanf("%d", &k);


    int temp[n];


    // rotation logic
    for(int i = 0; i < n; i++)
    {
        temp[(i + k) % n] = arr[i];
    }


    // print result
    printf("Rotated array: ");

    for(int i = 0; i < n; i++)
    {
        printf("%d ", temp[i]);
    }


    return 0;
}
