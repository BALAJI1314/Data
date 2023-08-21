#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Structure to represent a Queue
struct Queue {
    int data[MAX_SIZE];
    int front, rear;
};

// Initialize an empty queue
void initializeQueue(struct Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Check if the queue is empty
bool isEmpty(struct Queue *q) {
    return q->front == -1;
}

// Check if the queue is full
bool isFull(struct Queue *q) {
    return (q->rear + 1) % MAX_SIZE == q->front;
}

// Add an element to the rear of the queue (ENQUEUE)
void enqueue(struct Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }

    if (isEmpty(q))
        q->front = 0;

    q->rear = (q->rear + 1) % MAX_SIZE;
    q->data[q->rear] = value;
    printf("%d enqueued to the queue.\n", value);
}

// Remove an element from the front of the queue (DEQUEUE)
void dequeue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }

    printf("%d dequeued from the queue.\n", q->data[q->front]);

    if (q->front == q->rear)
        initializeQueue(q);
    else
        q->front = (q->front + 1) % MAX_SIZE;
}

// Display the elements of the queue
void display(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    int i = q->front;
    while (i != q->rear) {
        printf("%d ", q->data[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("%d\n", q->data[i]);
}

int main() {
    struct Queue q;
    initializeQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    display(&q);

    dequeue(&q);

    display(&q);

    return 0;
}

