//Delete Last Node of single linked list

#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *link;
};

int getData(struct node *head, int numberOfNode);
int DeleteLastNode(struct node *head);
int printData(struct node *head);

int getData(struct node *head, int numberOfNode)
{
    struct node *ptr = head;

    for(int i = 1 ; i < numberOfNode ;i++)
    {
      struct node *temp = (struct node *) malloc (sizeof(struct node));
      printf("Enter the %d Data : ",i+1);
      scanf("%d",&temp -> data);

      ptr -> link = temp;
      temp -> link = NULL;
      ptr = temp;
    }
return 0;
}

int DeleteLastNode(struct node *head) {
    if (head == NULL) {
        printf("Linked List is Empty\n");
        return 1;
    }

    struct node *temp = head;
    struct node *prev = NULL;

    // Traverse to the last node
    while (temp->link != NULL) {
        prev = temp;
        temp = temp->link;
    }

    // If there is only one node
    if (prev == NULL) {
        free(temp);
        head = NULL; // Update the head to NULL
    } else {
        // Update the link of the second-to-last node to NULL
        prev->link = NULL;
        free(temp);
    }

    return 0;
}

int printData(struct node *head)
{
    struct node *ptr = head;

    printf("Data are : ");
    while(head != NULL)
    {
        printf("%d \t",ptr -> data);
        ptr = ptr -> link;
    }
}

int main()
{

    int numberOfNode;
    printf("Enter Number Of Node : ");
    scanf("%d",&numberOfNode);

    struct node *head = (struct node *) malloc (sizeof(struct node));

    printf("Enter 1st Data :");
    scanf("%d",&head -> data);

    head -> link = NULL;

    getData(head,numberOfNode);

    DeleteLastNode(head);

    printData(head);

    return 0;
}


/*

another Method


//Delete last Node of single linked list

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};

int getData(struct node *head, int numberOfNode);
int DeleteFirstNode(struct node *head);
int printData(struct node *head);

int getData(struct node *head, int numberOfNode)
{
    struct node *ptr = head;

    for(int i = 1 ; i < numberOfNode ; i++)
    {
        struct node *temp = (struct node *) malloc (sizeof(struct node));
        printf("Enter %d Data : ",i+1);
        scanf("%d",&temp -> data);

        ptr -> link = temp;
        temp -> link = NULL;
        ptr = temp;
    }
    return 0;
}

int DeleteFirstNode(struct node *head)
{
    if (head == NULL)
    {
        printf("Linked List is Empty\n");
        return 1;
    }
    else if(head -> link == NULL)
    {
        free(head);
        head = NULL;
    }
    else{
      struct node *temp = head;

      while(temp->link -> link!= NULL)
      {
          temp = temp -> link;

      }
      free(temp -> link);
      temp -> link = NULL;
    }



    return head;
}

int printData(struct node *head)
{
    struct node *ptr = head;

    printf("Data are : ");
    while( ptr != NULL)
    {
        printf("%d \t",ptr -> data);
        ptr = ptr -> link;
    }
}

int main()
{

    int numberOfNode;
    printf("Enter Number Of Node : ");
    scanf("%d",&numberOfNode);

    struct node *head = (struct node *) malloc (sizeof(struct node));

    printf("Enter 1st Data :");
    scanf("%d",&head -> data);

    head -> link = NULL;

    getData(head,numberOfNode);

    //must be declaring head
    head = DeleteFirstNode(head);

    printData(head);

    return 0;
}



*/



