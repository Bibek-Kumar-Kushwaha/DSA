//Insert a node at the end in doubly linked list
#include<stdio.h>
#include<stdlib.h>
struct node {
    struct node *prev;
    int data;
    struct node *next;
};
int insertAtBeginning(struct node *head);

int insertAtEnd(struct node *head)
{
    struct node *temp = (struct node *) malloc(sizeof(struct node));
    struct node *tp;
    temp->prev = NULL;
    temp->data = 10;
    temp->next = NULL;

    tp = head;

    while(tp -> next != NULL)
    {
        tp = tp -> next;
    }
    tp -> next  = temp;
    temp -> prev = tp;
    return head;

}

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

    head = insertAtEnd(head);

    struct node *ptr = head;
    do {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    } while (ptr != NULL);


}

