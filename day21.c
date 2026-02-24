#include <stdio.h>
#include <stdlib.h>

// structure of node
struct Node
{
    int data;
    struct Node* next;
};

int main()
{
    int n, value;

    struct Node *head = NULL;
    struct Node *temp = NULL;
    struct Node *newNode = NULL;

    
    // input number of nodes
    scanf("%d", &n);

    
    // create linked list
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &value);

        
        newNode = (struct Node*)malloc(sizeof(struct Node));

        
        newNode->data = value;
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


    
    // traverse and print
    temp = head;

    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
