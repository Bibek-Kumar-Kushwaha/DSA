//Delete Certain position Node of single linked list
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};

int getData(struct node *head, int numberOfNode);
void DeleteCertainNode(struct node **head, int position);
void printData(struct node *head);

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

void DeleteCertainNode(struct node **head, int position)
{
    struct node *current = *head;
    struct node *previous = *head;

    if (*head == NULL)
    {
        printf("List is empty ");
    }
    else if (position == 1)
    {
        *head = current -> link;
        free(current);
        current = NULL;
    }
    else
    {
        while (position != 1)
        {
            previous = current;
            current = current -> link ;
            position--;
        }
        previous -> link = current -> link;
        free(current);
        current = NULL;
    }
}

void printData(struct node *head)
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
    int numberOfNode, position;
    printf("Enter Number Of Node : ");
    scanf("%d", &numberOfNode);

    printf("Enter Position Of Node you want to Delete : ");
    scanf("%d", &position);

    struct node *head = (struct node *) malloc (sizeof(struct node));

    printf("Enter 1st Data :");
    scanf("%d", &head -> data);

    head -> link = NULL;

    getData(head, numberOfNode);

    DeleteCertainNode(&head, position);

    printData(head);

    return 0;
}
