//Doubly Circular Linked list
#include<stdio.h>
#include<stdlib.h>
struct node
{
 struct node *prev;
 int data;
 struct node *next;
};

 void main()
 {
     struct node *tail = (struct node*) malloc (sizeof(struct node));

     tail -> data = 45;
     tail -> next = tail;
     tail -> prev = tail;

     printf("%d",tail);
     printf("\n%d",tail -> next);
     printf("\n%d",tail -> prev);

     free(tail);
 }
