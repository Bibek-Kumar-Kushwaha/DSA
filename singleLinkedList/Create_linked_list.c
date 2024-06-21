//Creating new Single Listed Link

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
 struct node{
  int data;
  struct node *link;
 };
 void main()
 {
     struct node *head = NULL;
     head = (struct node *)malloc(sizeof(struct node));

     head -> data = 45;
     head -> link = NULL;

     printf("%d",head -> data);
     return 0;
 }
