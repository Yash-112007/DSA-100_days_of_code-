#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node
{
    int data;
    struct Node* next;
};

// function to create list
struct Node* createList(int n)
{
    struct Node *head = NULL, *temp = NULL, *newNode;
    int value;

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

    return head;
}


// function to merge lists
struct Node* mergeList(struct Node* head1, struct Node* head2)
{
    struct Node *result = NULL, *temp = NULL;

    if(head1 == NULL) return head2;
    if(head2 == NULL) return head1;

    // set first node
    if(head1->data < head2->data)
    {
        result = head1;
        head1 = head1->next;
    }
    else
    {
        result = head2;
        head2 = head2->next;
    }

    temp = result;

    // merge process
    while(head1 != NULL && head2 != NULL)
    {
        if(head1->data < head2->data)
        {
            temp->next = head1;
            head1 = head1->next;
        }
        else
        {
            temp->next = head2;
            head2 = head2->next;
        }

        temp = temp->next;
    }

    // attach remaining
    if(head1 != NULL)
        temp->next = head1;

    if(head2 != NULL)
        temp->next = head2;

    return result;
}


// function to print list
void printList(struct Node* head)
{
    while(head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}


int main()
{
    int n, m;

    // input first list
    scanf("%d", &n);
    struct Node* head1 = createList(n);

    // input second list
    scanf("%d", &m);
    struct Node* head2 = createList(m);

    // merge
    struct Node* merged = mergeList(head1, head2);

    // print result
    printList(merged);

    return 0;
}
