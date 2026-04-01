#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// inorder me element search karne ke liye
int search(int inorder[], int start, int end, int value) {
    for(int i = start; i <= end; i++) {
        if(inorder[i] == value)
            return i;
    }
    return -1;
}

// tree construct function
Node* buildTree(int preorder[], int inorder[], int start, int end, int *preIndex) {
    if(start > end)
        return NULL;

    // preorder ka current element root hai
    Node* root = newNode(preorder[*preIndex]);
    (*preIndex)++;

    // leaf node case
    if(start == end)
        return root;

    int inIndex = search(inorder, start, end, root->data);

    root->left  = buildTree(preorder, inorder, start, inIndex - 1, preIndex);
    root->right = buildTree(preorder, inorder, inIndex + 1, end, preIndex);

    return root;
}

// postorder traversal
void postorder(Node* root) {
    if(root == NULL) return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    int n;
    scanf("%d", &n);

    int preorder[n], inorder[n];

    for(int i=0;i<n;i++)
        scanf("%d", &preorder[i]);

    for(int i=0;i<n;i++)
        scanf("%d", &inorder[i]);

    int preIndex = 0;
    Node* root = buildTree(preorder, inorder, 0, n-1, &preIndex);

    postorder(root);
    return 0;
}
