#include <stdio.h>
#include <stdlib.h>

// Stack structure
struct Stack {
    int *arr;
    int top;
    int capacity;
};

// Queue structure
struct Queue {
    int *arr;
    int front, rear, size, capacity;
};

// Stack functions
struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->arr = (int*)malloc(capacity * sizeof(int));
    return stack;
}

int isStackEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void push(struct Stack* stack, int x) {
    stack->arr[++stack->top] = x;
}

int pop(struct Stack* stack) {
    return stack->arr[stack->top--];
}

// Queue functions
struct Queue* createQueue(int capacity) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->capacity = capacity;
    q->front = 0;
    q->size = 0;
    q->rear = capacity - 1;
    q->arr = (int*)malloc(capacity * sizeof(int));
    return q;
}

int isQueueEmpty(struct Queue* q) {
    return q->size == 0;
}

void enqueue(struct Queue* q, int x) {
    q->rear = (q->rear + 1) % q->capacity;
    q->arr[q->rear] = x;
    q->size++;
}

int dequeue(struct Queue* q) {
    int x = q->arr[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return x;
}

// Function to reverse queue
void reverseQueue(struct Queue* q) {
    struct Stack* stack = createStack(q->capacity);

    // Step 1: Push all queue elements to stack
    while (!isQueueEmpty(q)) {
        push(stack, dequeue(q));
    }

    // Step 2: Pop from stack and enqueue back
    while (!isStackEmpty(stack)) {
        enqueue(q, pop(stack));
    }
}

// Main function
int main() {
    int N;
    scanf("%d", &N);

    struct Queue* q = createQueue(N);

    // Input queue elements
    for (int i = 0; i < N; i++) {
        int x;
        scanf("%d", &x);
        enqueue(q, x);
    }

    // Reverse queue
    reverseQueue(q);

    // Print reversed queue
    while (!isQueueEmpty(q)) {
        printf("%d ", dequeue(q));
    }

    return 0;
}
