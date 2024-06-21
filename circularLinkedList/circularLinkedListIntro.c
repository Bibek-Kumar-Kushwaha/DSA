//Single Circular Linked list
#include<stdio.h>
#include<stdlib.h>
struct node
{
 int data;
 struct node *link;
};

 void main()
 {
     struct node *tail = (struct node*) malloc (sizeof(struct node));
     tail -> data = 45;
     tail -> link = tail;

     printf("%d",tail);
     printf("\n%d",tail -> link);
 }
