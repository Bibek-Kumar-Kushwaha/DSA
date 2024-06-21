//Insert node at end
#include<stdio.h>
#include<conio.h>
 struct node {
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

     add_node_end(head);
     print_data(head);
 }
  void  add_node_end(struct node *head)
  {
      struct node *temp, *ptr;
      ptr = head;
      temp = (struct node *) malloc (sizeof(struct node));
      temp -> data = 135;
      temp -> link = NULL;

      while(ptr -> link != NULL)
      {
          ptr = ptr ->link;
      }
      ptr -> link = temp;
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
