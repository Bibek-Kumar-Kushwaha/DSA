//WAP to sort array using Circular Queue structure
#include <stdio.h>
#define MAX_SIZE 5

// Circular Queue structure
struct CircularQueue
{
    int items[MAX_SIZE];
    int front, rear;
};

// Function prototypes
void initializeQueue(struct CircularQueue *q);
int isFull(struct CircularQueue *q);
int isEmpty(struct CircularQueue *q);
void enqueue(struct CircularQueue *q, int value);
int dequeue(struct CircularQueue *q);
void display(struct CircularQueue *q);

int main()
{
    struct CircularQueue q;
    int choice, value;
    initializeQueue(&q);
    while (1)
    {
        printf("\n1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            if (isFull(&q))
                printf("Queue is full.\n");
            else
            {
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(&q, value);
            }
            break;
        case 2:
            if (isEmpty(&q))
                printf("Queue is empty.\n");
            else
                printf("Dequeued element: %d\n", dequeue(&q));
            break;
        case 3:
            display(&q);
            break;
        case 4:
            printf("Exiting program.\n");
            return 0;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}

// Function to initialize the circular queue
void initializeQueue(struct CircularQueue *q)
{
    q->front = q->rear = -1;
}

// Function to check if the circular queue is full
int isFull(struct CircularQueue *q)
{
    return (q->front == 0 && q->rear == MAX_SIZE - 1) ||
           (q->front == q->rear + 1);
}

// Function to check if the circular queue is empty
int isEmpty(struct CircularQueue *q)
{
    return q->front == -1;
}

// Function to enqueue an element into the circular queue
void enqueue(struct CircularQueue *q, int value)
{
    if (isEmpty(q))
        q->front = 0;
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->items[q->rear] = value;
    printf("Enqueued %d successfully.\n", value);
}

// Function to dequeue an element from the circular queue
int dequeue(struct CircularQueue *q)
{
    int value = q->items[q->front];
    if (q->front == q->rear)
        initializeQueue(q);
    else
        q->front = (q->front + 1) % MAX_SIZE;
    return value;
}

// Function to display the elements of the circular queue
void display(struct CircularQueue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty.\n");
        return;
    }

    printf("Elements of the queue: ");
    int i = q->front;
    while (i != q->rear)
    {
        printf("%d ", q->items[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("%d\n", q->items[q->rear]);
}
