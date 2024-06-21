//Single Circular Linked list insert node at begining
#include<stdio.h>
#include<stdlib.h>

struct node
{
 int data;
 struct node *link;
};

 void main()
 {
    struct node *tail = (struct node*) malloc(sizeof(struct node));
    tail->data = 45;
    tail->link = tail;

    struct node *newP = (struct node*) malloc(sizeof(struct node));
    newP->data = 65;

    newP->link = tail;
    tail->link = newP;

    struct node *temp = tail->link;
     do
     {
        printf("%d\t",temp -> data);
        temp = temp ->link;
     }
     while(temp != tail -> link );

 }

