#include<stdio.h>
#include<stdlib.h>
 struct node{
    int data;
    struct node *link;
 };

void main()
{
    struct node *head = (struct node *) malloc (sizeof(struct node));
    head -> data = 45;
    head -> link = NULL;

    struct node *current = (struct node *) malloc (sizeof(struct node));
    current -> data = 90;
    current -> link = NULL;
    head -> link = current;

    current = (struct node *) malloc (sizeof(struct node));
    current -> data = 135;
    current -> link = NULL;
    head -> link ->link = current;

    current = (struct node *) malloc (sizeof(struct node));
    current -> data = 180;
    current -> link = NULL;
    head -> link ->link -> link = current;

    print_data(head);

}

void print_data(struct node *head)
{
    if(head == NULL)
    {
        printf(" Linked List is Empty");
    }
    else
    {
        struct node *ptr = NULL;
        ptr = head;
        while(ptr != NULL)
        {
            printf("%d \t",ptr -> data);
            ptr = ptr ->link;
        }
    }
}
