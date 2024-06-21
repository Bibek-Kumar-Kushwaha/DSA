//WAP to implement of array in stack
#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 20
int stack[MAX_SIZE];
int top = -1;
void push(int x) {
    if (top >= MAX_SIZE - 1) {
        printf("Stack Overflow\n");
    } else {
        top++;
        stack[top] = x;
        printf("%d pushed to stack\n", x);
    }
}

int pop() {
    if (top < 0) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        int item = stack[top];
        top--;
        return item;
    }
}

void display() {
    if (top < 0) {
        printf("Stack is Empty\n");
    } else {
        printf("Stack elements are:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

bool isEmpty() {
    return (top < 0);
}

bool isFull() {
    return (top >= MAX_SIZE - 1);
}

int main() {
    int choice, item;
    char cont;

    do {
        printf("\nStack Implementation\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Check if empty\n");
        printf("5. Check if full\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter an element to push: ");
                scanf("%d", &item);
                push(item);
                break;
            case 2:
                item = pop();
                if (item != -1)
                    printf("Popped element: %d\n", item);
                break;
            case 3:
                display();
                break;
            case 4:
                if (isEmpty())
                    printf("Stack is empty\n");
                else
                    printf("Stack is not empty\n");
                break;
            case 5:
                if (isFull())
                    printf("Stack is full\n");
                else
                    printf("Stack is not full\n");
                break;
            default:
                printf("Invalid choice\n");
        }

        printf("Do you want to continue (y/n): ");
        scanf(" %c", &cont);

    } while (cont == 'y' || cont == 'Y');

    return 0;
}
