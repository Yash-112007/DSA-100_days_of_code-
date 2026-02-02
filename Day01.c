#include <stdio.h>

int main()
{
    int n;
    int arr[50];
    int pos, x;
    int i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter position: ");
    scanf("%d", &pos);

    printf("Enter element to insert: ");
    scanf("%d", &x);

    for(i = n - 1; i >= pos - 1; i--)
    {
        arr[i + 1] = arr[i];
    }

    arr[pos - 1] = x;

    printf("Updated array:\n");
    for(i = 0; i < n + 1; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
