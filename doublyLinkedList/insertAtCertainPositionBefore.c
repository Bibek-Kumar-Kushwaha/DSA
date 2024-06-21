#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

struct node* insertAtBeginning(struct node *head)
{
    struct node *temp = (struct node *) malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = 30;
    temp->next = head;

    if (head != NULL) {
        head->prev = temp;
    }

    head = temp;
    return head;
}

struct node* insertAtBeforeCertainPosition(struct node *head)
{
    struct node *temp = (struct node *) malloc(sizeof(struct node));
    struct node *tp, *tp2;
    temp->prev = NULL;
    temp->data = 40;
    temp->next = NULL;

    tp = head;
    int pos = 3;
    while (pos != 1 && tp != NULL)
    {
        tp = tp->next;
        pos--;
    }

    if (tp == NULL) {
        printf("Position not found.\n");
        free(temp);
        return head;
    }

    tp2 = tp->prev;

    if (tp2 != NULL) {
        tp2->next = temp;
    } else {
        // If inserting before the head, update the head
        head = temp;
    }

    temp->prev = tp2;
    tp->prev = temp;
    temp->next = tp;

    return head;
}

int main()
{
    struct node *head = (struct node *) malloc(sizeof(struct node));
    head->prev = NULL;
    head->data = 10;
    head->next = NULL;

    struct node *current = (struct node *) malloc(sizeof(struct node));
    current->prev = NULL;
    current->data = 20;
    current->next = NULL;

    head->next = current;
    current->prev = head;

    head = insertAtBeginning(head);
    head = insertAtBeforeCertainPosition(head);

    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }

    return 0;
}
