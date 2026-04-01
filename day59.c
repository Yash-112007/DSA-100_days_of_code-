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

int search(int inorder[], int start, int end, int value) {
    for(int i = start; i <= end; i++)
        if(inorder[i] == value)
            return i;
    return -1;
}

Node* buildTree(int inorder[], int postorder[], int start, int end, int *postIndex) {
    if(start > end)
        return NULL;

    // last element of postorder = root
    Node* root = newNode(postorder[*postIndex]);
    (*postIndex)--;

    // leaf node
    if(start == end)
        return root;

    int inIndex = search(inorder, start, end, root->data);

    // IMPORTANT: build right first
    root->right = buildTree(inorder, postorder, inIndex + 1, end, postIndex);
    root->left  = buildTree(inorder, postorder, start, inIndex - 1, postIndex);

    return root;
}

// preorder traversal
void preorder(Node* root) {
    if(root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    int inorder[n], postorder[n];

    for(int i=0;i<n;i++)
        scanf("%d", &inorder[i]);

    for(int i=0;i<n;i++)
        scanf("%d", &postorder[i]);

    int postIndex = n - 1;
    Node* root = buildTree(inorder, postorder, 0, n-1, &postIndex);

    preorder(root);
    return 0;
}
