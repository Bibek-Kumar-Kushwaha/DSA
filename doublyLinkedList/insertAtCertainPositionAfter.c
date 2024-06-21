
//Insert a node at the end in doubly linked list
#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
int insertAtBeginning(struct node *head)
{
    struct node *temp = (struct node *) malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = 30;
    temp->next = NULL;

    temp -> next = head;
    head -> prev = temp;

    head = temp;
    return head;
}

int insertAtAfterCertainPosition
(struct node *head)
{
    struct node *temp = (struct node *) malloc(sizeof(struct node));
    struct node *tp,*tp2;
    temp->prev = NULL;
    temp->data = 40;
    temp->next = NULL;

    tp = head;
    int pos = 2;
    while(pos != 1)
    {

        tp = tp -> next;
        pos--;
    }

    if(tp -> next == NULL)
    {
        tp -> next = temp;
        temp -> prev = tp;
    }
    else
    {
        tp2 = tp -> next;

        tp -> next = temp;
        temp -> prev = tp;

        tp2 -> prev = temp;
        temp -> next = tp2;


        return head;
    }

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
    head = insertAtAfterCertainPosition(head);

    struct node *ptr = head;
    do
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
    while (ptr != NULL);


}

