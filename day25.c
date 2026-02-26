#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

int main()
{
    int n, key, count = 0;

    // Head pointer
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    // Create linked list
    printf("Enter %d elements:\n", n);

    for(int i = 0; i < n; i++)
    {
        newNode = (struct Node*)malloc(sizeof(struct Node));

        scanf("%d", &newNode->data);

        newNode->next = NULL;

        if(head == NULL)
        {
            head = newNode;
            temp = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }

    // Input key
    printf("Enter key to count: ");
    scanf("%d", &key);

    // Traverse and count
    temp = head;

    while(temp != NULL)
    {
        if(temp->data == key)
        {
            count++;
        }
        temp = temp->next;
    }

    // Output result
    printf("Count = %d\n", count);

    return 0;
}
