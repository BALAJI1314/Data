#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_STACK_SIZE 100

typedef struct {
    int data[MAX_STACK_SIZE];
    int top;
} Stack;

void initialize(Stack *stack) {
    stack->top = -1;
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

int isFull(Stack *stack) {
    return stack->top == MAX_STACK_SIZE - 1;
}

void push(Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow!\n");
        exit(EXIT_FAILURE);
    }
    stack->data[++stack->top] = value;
}

int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow!\n");
        exit(EXIT_FAILURE);
    }
    return stack->data[stack->top--];
}

int evaluatePostfix(char *expression) {
    Stack stack;
    initialize(&stack);

    for (int i = 0; expression[i] != '\0'; i++) {
        if (isdigit(expression[i])) {
            push(&stack, expression[i] - '0');
        } else {
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);
            int result;

            switch (expression[i]) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
                default:
                    printf("Invalid operator!\n");
                    exit(EXIT_FAILURE);
            }

            push(&stack, result);
        }
    }

    return pop(&stack);
}

int main() {
    char expression[100];
    printf("Enter a postfix expression: ");
    scanf("%s", expression);

    int result = evaluatePostfix(expression);
    printf("Result: %d\n", result);

    return 0;
}

