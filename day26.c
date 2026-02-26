#include <stdio.h>
#include <stdlib.h>

// Doubly Linked List Node
struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
};

int main()
{
    int n;

    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);

    for(int i = 0; i < n; i++)
    {
        // Memory allocation
        newNode = (struct Node*)malloc(sizeof(struct Node));

        scanf("%d", &newNode->data);

        newNode->next = NULL;
        newNode->prev = NULL;

        // First node
        if(head == NULL)
        {
            head = newNode;
            temp = newNode;
        }
        else
        {
            temp->next = newNode;
            newNode->prev = temp;
            temp = newNode;
        }
    }

    // Forward Traversal
    printf("Linked List in forward order:\n");

    temp = head;

    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
