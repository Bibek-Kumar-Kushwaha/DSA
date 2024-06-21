//Create Linked List (Link two data)
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

     struct node *current1 = (struct node *)malloc(sizeof(struct node));
     current1 -> data = 20;
     current1 -> link = NULL;

     head -> link = current1;

     //value
     printf("\nValue of Head is %d",head -> data);
     printf("\nValue of current1 is %d",current1 -> data);

     //address
     printf("\nAddress of Head is %d",head -> link);
     printf("\nAddress of current1 is %d",current1 -> link);
 }
