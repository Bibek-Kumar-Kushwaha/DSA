//Create Linked List (Link Three data)
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
 struct node {
   int data;
   struct node *link;
 };

 void main()
 {
     struct node *head = (struct node *)malloc(sizeof(struct node));
     head -> data = 10;
     head -> link = NULL;

     struct node *current = (struct node *)malloc(sizeof(struct node));
     current -> data = 20;
     current -> link = NULL;
     head -> link = current;

     current = malloc(sizeof(struct node));
     current -> data = 30;
     current-> link = NULL;

     head -> link -> link = current;

     printf("%d",current);
     printf("\n%d",current -> data);

 }
