//Create a doubly linked list using two node
#include<stdio.h>
#include<stdlib.h>

struct node {
    struct node *prev;
    int data;
    struct node *next;
};

int main() {
    struct node *head = (struct node *) malloc(sizeof(struct node));
    head->prev = NULL;
    head->data = 8;
    head->next = NULL;

    struct node *current = (struct node *) malloc(sizeof(struct node));
    current->prev = NULL;
    current->data = 18;
    current->next = NULL;

    head->next = current;
    current->prev = head;

    struct node *ptr = head;
    do {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    } while (ptr != NULL);


}
