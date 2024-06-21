
#include<stdio.h>
#include<stdlib.h>
 struct node
 {
     int data;
     struct node *link;
 };

 /* *************** Define function *************** */
 int addMoreData(struct node *head, int nodeNumber);
 int insertDataAtFirst(struct node **head);
 int deleteFirstNode(struct node *head);
 int insertDataAtLast(struct node *head);
 int deleteLastNode(struct node *head);
 int insertDataAtCertainPosition(struct node *head);
 int deleteCertainPositionNode(struct node *head);
 int printData(struct node *head);

 /* *************** Add More Data In Linked List *************** */
int addMoreData(struct node *head, int nodeNumber)
{
    struct node *ptr = head;

    for(int i = 1; i < nodeNumber; i++)
    {
        struct node *current = (struct node *) malloc (sizeof(struct node));

        printf("Enter %d node data : ",i+1);
        scanf("%d",&current -> data);

        ptr -> link = current;
        current -> link = NULL;
        ptr = current;
    }

return head;
}

/* *************** Insert Data at the first of linked List *************** */
int insertDataAtFirst(struct node **head)
{
    printf("%d head \n",head);
    printf("%d *head\n",*head);
    printf("%d *head\n",**head);

    struct node *ptr = (struct node *) malloc (sizeof(struct node));
    printf("Enter Node Data for Insert At first : ");
    scanf("%d",&ptr -> data);
    ptr->link = *head;
    *head = ptr;

}

/* *************** Delete First Node of linked list *************** */
int deleteFirstNode(struct node *head)
{

 if (head == NULL)
    {
        printf("Linked List is Empty\n");
        return 1;
    }
    else{
      struct node *temp = head;
      head = head -> link;
      free(temp);
      temp = NULL;
    }
    return head;
}

/* *************** Insert Data at the last of linked list *************** */
int insertDataAtLast(struct node *head)
{
    struct node *temp = (struct node *) malloc (sizeof(struct node));
    struct node *ptr = head;

    while(ptr -> link != NULL)
    {
      ptr = ptr -> link;
    }
    printf("Enter Node Data for Insert At Last : ");
    scanf("%d",&temp -> data);
    temp -> link = NULL;
    ptr -> link = temp;
}

/* *************** Delete last Node of linked list *************** */
int deleteLastNode(struct node *head)
{
    struct node *temp = head;
    struct node *prev = NULL;

    while(temp -> link != NULL)
    {
        prev = temp;
        temp = temp ->link;
    }

    if(temp == head)
    {
        head = NULL;
        free(temp);
    }
    else
    {
        prev -> link = NULL;
        free(temp);
    }

}

/* *************** Insert Data at the Certain Position of linked list  *************** */
int insertDataAtCertainPosition(struct node *head)
{
    struct node *temp = (struct node *) malloc (sizeof(struct node));
    struct node *ptr = head;
    int position;
    printf("Enter Position of Node you Want to add Data : ");
    scanf("%d",&position);

    printf("Enter Data for Insert at %d node position: ",position);
    scanf("%d",&temp -> data);

    position--;
    while(position != 1)
    {
      ptr = ptr ->link;
      position--;
    }


    temp->link = ptr->link;
    ptr->link = temp;
}

/* *************** Delete Node at Certain Position of linked list  *************** */
 int deleteCertainPositionNode(struct node *head)
 {
    struct node *temp = head;
    struct node *next;
    int position;
    printf("Enter Position of Node you Want to Delete : ");
    scanf("%d",&position);

    position--;
    while(position != 1)
    {
      temp = temp -> link;
      position--;
    }
    next = temp -> link;
    temp->link = next -> link;
    free(next);
 }

/* *************** Print all the of linked list *************** */
 int printData(struct node *head)
 {
     struct node *ptr = head;
     printf("Your Data are : ");
     while(ptr != NULL)
     {
         printf("%d\t",ptr -> data);
         ptr = ptr -> link;
     }
 }

 /* *************** Main function *************** */
 void main()
 {
     int nodeNumber;
     printf("Enter Number of Node : ");
     scanf("%d",&nodeNumber);

     struct node *head = (struct node *) malloc (sizeof(struct node));
     printf("Enter 1 node data : ");
     scanf("%d",&head -> data);
     head -> link = NULL;

     printf("*d main *head\n",*head);
     addMoreData(head,nodeNumber);
int n,exit;
printf("Enter \n 1 for insertDataAtFirst \n 2 for insertDataAtLast \n 3 for insertDataAtCertainPosition \n 4 for deleteFirstNode \n 5 for deleteLastNode \n 6 for deleteCertainPositionNode \n 7 for Exit from Program \n\n");
scanf("%d",&n);

while(exit != 7)
{
switch (n) {
    case 1:
        insertDataAtFirst(&head);
        break;
    case 2:
        insertDataAtLast(head);
        break;
    case 3:
        insertDataAtCertainPosition(head);
        break;
    case 4:
        head = deleteFirstNode(head);
        break;
    case 5:
        deleteLastNode(head);
        break;
    case 6:
        deleteCertainPositionNode(head);
        break;
    default:
        printf("Invalid choice\n");
        break;
}
        printf("If You Want Continue Operation Then choose from 1-6 \n");
        printf("You Want To Exit , Press 7 : ");
        scanf("%d",&exit);
        printf("\n");
}

     printData(head);
 }
