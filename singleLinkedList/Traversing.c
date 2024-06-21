//Traversing a single linked list
// Count no. of node using traversing
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



    count_of_nodes(head);

    return 0;
}

void count_of_nodes(struct node *head)
{
    int count = 0;
    if(head == NULL)
    {
        printf("Linked List is empty");
    }
    else
    {
        struct node *ptr = NULL;
        ptr = head;
        while(ptr != NULL)
        {
            count++;
            ptr = ptr->link;
        }
        printf("Total no. of Node is %d",count);
    }
}
