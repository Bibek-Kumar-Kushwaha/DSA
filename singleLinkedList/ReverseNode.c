
//Reverse Node of single linked list

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};

int getData(struct node *head, int numberOfNode);
int RevreseNode(struct node *head);
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

int RevreseNode(struct node *head)
{
    struct node *temp = NULL, *temp2 = NULL;

     while(head != NULL)
     {
        temp2 = head -> link;
        head -> link = temp;
        temp = head;
        head = temp2;
     }
     head = temp;
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
    head = RevreseNode(head);

    printData(head);

    return 0;
}








