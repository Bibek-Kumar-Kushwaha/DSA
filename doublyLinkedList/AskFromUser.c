//Create a Doubly Linked list Ask from User
#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
//create doubly linked list
int createList(struct node *head,int node)
{
    struct node *current = head;

    for(int i=1 ; i < node ; i++)
    {
        struct node *newNode = (struct node *) malloc (sizeof(struct node));

        printf("Enter the element for the node %d: ",i+1);
        scanf("%d",&newNode -> data);

        current -> next = newNode;
        newNode -> prev = current;
        newNode -> next = NULL;
        current = newNode;
    }

    return head;
}

//Insert node at first
int insertAtFirst(struct node *head)
{
    struct node *temp = head;

    struct node *newNode = (struct node *) malloc (sizeof(struct node));
    newNode -> prev = NULL;

    printf("Enter element of insert at first node :");
    scanf("%d",&newNode->data);

    newNode -> next = temp;
    temp -> prev = newNode;

    head = newNode;
    return head;
}
//Delete node present at first position
int deleteAtFirst(struct node *head)
{
    struct node *temp = head;

  if(temp -> prev == NULL)
   {
       free(temp);
       temp = temp -> next;
   }

   head = temp;

    return head;
}

//Insert node At last
int insertAtLast(struct node *head)
{
    struct node *temp = head;

    struct node *newNode = (struct node *) malloc (sizeof(struct node));
    newNode -> next = NULL;
    printf("Enter element of insert at Last node :");

    scanf("%d",&newNode->data);

    while(temp -> next != NULL)
    {
        temp = temp -> next;
    }

    temp -> next = newNode;
    newNode -> prev = temp;

    newNode = head;
    return head;
}

//Delete node At last
int deleteAtLast(struct node *head)
{
    struct node *temp = head;
    struct node *temp2;

    while(temp -> next != NULL)
    {
      temp = temp -> next;
    }
    temp2 = temp -> prev;
    temp2 -> next = NULL;

    free(temp);

    return head;
}

// Insert node at certain position
struct node* insertAtCertainPosition(struct node *head) {
    int position;
    printf("Enter position of node where you want to insert: ");
    scanf("%d", &position);

    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    printf("Enter element to insert at certain position: ");
    scanf("%d", &newNode->data);

    if (position == 1) {
        newNode->prev = NULL;
        newNode->next = head;
        if (head != NULL)
            head->prev = newNode;
        return newNode;
    }

    struct node *temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Invalid position.\n");
        return head;
    }

    newNode->prev = temp;
    newNode->next = temp->next;

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;

    return head;
}

//Delete node at certain position
struct node* deleteAtCertainPosition(struct node *head) {
    int position;
    printf("Enter position of node where you want to Delete: ");
    scanf("%d", &position);

    if (position < 1) {
        printf("Invalid position.\n");
        return head;
    }

    if (position == 1) {
        struct node *temp = head;
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        free(temp);
        return head;
    }

    struct node *temp = head;
    for (int i = 1; i < position && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Invalid position.\n");
        return head;
    }

    temp->prev->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    free(temp);

    return head;
}


int printData(struct node *head)
{

    while(head != NULL)
    {
        printf("%d\t",head -> data);
        head = head -> next;
    }

}

int main()
{
    int node;
    printf("Enter Number of Node : ");
    scanf("%d",&node);

    if(node == 0)
    {
        printf("You haven't any node");
        return 0;
    }

    struct node *head = (struct node *) malloc (sizeof(struct node));
    head -> prev = NULL;
    head -> next = NULL;

    printf("Enter the element for the node 1: ");
    scanf("%d",&head -> data);

    head = createList(head,node);

    int n,exit;


while(exit != 7)
{
printf("Enter \n 1 for insertDataAtFirst \n 2 for insertDataAtLast \n 3 for insertDataAtCertainPosition \n 4 for deleteFirstNode \n 5 for deleteLastNode \n 6 for deleteCertainPositionNode \n 7 for Exit from Program \n\n");
scanf("%d",&n);
switch (n) {
    case 1:
        head = insertAtFirst(head);
        break;
    case 2:
        head = insertAtLast(head);
        break;
    case 3:
        head = insertAtCertainPosition(head);
        break;
    case 4:
         head = deleteAtFirst(head);
        break;
    case 5:
        head = deleteAtLast(head);
        break;
    case 6:
        head = deleteAtCertainPosition(head);
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


    return 0;
}
