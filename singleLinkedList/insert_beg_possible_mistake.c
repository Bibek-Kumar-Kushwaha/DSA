#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *link;
};

// Function to add a node at the beginning of the linked list
//double pointer
void add_node_first(struct node **head) {
    struct node *ptr = (struct node *) malloc (sizeof(struct node));
    ptr->data = 10;
    ptr->link = *head;
    *head = ptr;
}

// Function to print the linked list
void print_data(struct node *head) {
    if (head == NULL) {
        printf("Linked List is Empty\n");
    } else {
        struct node *ptr = head;
        while (ptr != NULL) {
            printf("%d \t", ptr->data);
            ptr = ptr->link;
        }
        printf("\n");
    }
}

int main() {
    struct node *head = (struct node *) malloc (sizeof(struct node));
    head->data = 45;
    head->link = NULL;

    struct node *current = (struct node *) malloc (sizeof(struct node));
    current->data = 90;
    current->link = NULL;
    head->link = current;

    current = malloc(sizeof(struct node));
    current->data = 135;
    current->link = NULL;
    head->link->link = current;

    // Adding a node at the beginning with data 10

    //send address of head with reference
    add_node_first(&head);

    // Printing the linked list
    print_data(head);

    return 0;
}

