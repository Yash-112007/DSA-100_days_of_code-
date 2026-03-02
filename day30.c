#include <stdio.h>
#include <stdlib.h>

// Node structure for Polynomial
struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

// Function to create polynomial
struct Node* createPolynomial(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    for (int i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        
        scanf("%d %d", &newNode->coeff, &newNode->exp);
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    return head;
}

// Function to print polynomial
void printPolynomial(struct Node* head) {
    struct Node* temp = head;

    while (temp != NULL) {
        
        // Print coefficient
        printf("%d", temp->coeff);

        // Print variable part
        if (temp->exp > 1)
            printf("x^%d", temp->exp);
        else if (temp->exp == 1)
            printf("x");

        // Print + if not last term
        if (temp->next != NULL)
            printf(" + ");

        temp = temp->next;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    struct Node* head = createPolynomial(n);

    printPolynomial(head);

    return 0;
}
