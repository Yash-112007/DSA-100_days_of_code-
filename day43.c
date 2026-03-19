#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Queue for level order
struct Queue {
    struct Node** arr;
    int front, rear, size;
};

// Create new node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Create queue
struct Queue* createQueue(int size) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = 0;
    q->size = size;
    q->arr = (struct Node**)malloc(size * sizeof(struct Node*));
    return q;
}

int isEmpty(struct Queue* q) {
    return q->front == q->rear;
}

void enqueue(struct Queue* q, struct Node* node) {
    q->arr[q->rear++] = node;
}

struct Node* dequeue(struct Queue* q) {
    return q->arr[q->front++];
}

// Build tree from level order
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* root = newNode(arr[0]);
    struct Queue* q = createQueue(n);
    enqueue(q, root);

    int i = 1;

    while (!isEmpty(q) && i < n) {
        struct Node* current = dequeue(q);

        // Left child
        if (i < n && arr[i] != -1) {
            current->left = newNode(arr[i]);
            enqueue(q, current->left);
        }
        i++;

        // Right child
        if (i < n && arr[i] != -1) {
            current->right = newNode(arr[i]);
            enqueue(q, current->right);
        }
        i++;
    }

    return root;
}

// Inorder traversal
void inorder(struct Node* root) {
    if (root == NULL) return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Main
int main() {
    int N;
    scanf("%d", &N);

    int arr[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, N);

    inorder(root);

    return 0;
}
