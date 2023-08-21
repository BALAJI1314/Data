#include <stdio.h>
#define MAX_SIZE 100

// Structure to represent the stack
struct Stack {
    int arr[MAX_SIZE];
    int top;
};

// Initialize the stack
void initialize(struct Stack *stack) {
    stack->top = -1;
}

// Check if the stack is empty
int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

// Check if the stack is full
int isFull(struct Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

// Push an element onto the stack
void push(struct Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack is full. Cannot push.\n");
        return;
    }
    stack->arr[++stack->top] = value;
    printf("%d pushed onto the stack.\n", value);
}

// Pop an element from the stack
int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot pop.\n");
        return -1;
    }
    return stack->arr[stack->top--];
}

// Peek at the top element of the stack
int peek(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot peek.\n");
        return -1;
    }
    return stack->arr[stack->top];
}

int main() {
    struct Stack stack;
    initialize(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Top element: %d\n", peek(&stack));

    printf("Popped element: %d\n", pop(&stack));
    printf("Popped element: %d\n", pop(&stack));

    printf("Top element: %d\n", peek(&stack));

    return 0;
}

