#include<stdio.h>
#include<stdlib.h>

typedef struct Listt{
int blockNumber;
struct Listt *List;
}freeList;

freeList * getnode(int );
freeList * addFirst(freeList * ,int);
void display(freeList *);
void add_at_Location(freeList *,int );
freeList * delete(freeList *,int);

freeList *head;

int main()
{
int n,n2,choice,n4,n5;
freeList node1;
head = NULL;
do{
printf("\n0.Exit\n1.Create Linked List\n2.Traverse\n3.Add at first \n4.Add at particular location\n5.Delete node with particular value\n");
printf("\nChoose Operation no: ");
scanf("%d",&choice);

switch(choice)
{
case 1 :
    printf("\nEnter the node value: ");
    scanf("%d",&n);
    head = getnode(n);
    break;

case 2 :display(head);
    break;

case 3 :printf("\nEnter the data: ");
    scanf("%d",&n2);
    head = addFirst(head,n2);
    break;

case 4 :printf("\nEnter the location at which you want to insert value: ");
    scanf("%d",&n4);
    add_at_Location(head,n4);
    break;
case 5 :printf("\nEnter value of node to be deleted: ");
    scanf("%d",&n5);
    head = delete(head,n5);
    break;
case 0: break;
}
}while(choice!=0);
}

freeList* getnode(int n)
{
    freeList *p,*temp;
    p = (freeList *)malloc(sizeof(freeList));
    p->blockNumber = n;
    p->List = NULL;
    if(head == NULL)
        head = p;
    else
    {
        temp=head;
        while(temp->List != NULL)
            temp = temp->List;
        temp->List = p;
    }
    return(head);
}

void display(freeList * head)
{
    freeList *temp;
    temp = head;
    printf("\nData are \n");
    while(temp != NULL)
    {
        printf("%d  ",temp->blockNumber);
        temp = temp->List;
    }
}

freeList * addFirst(freeList * head,int x)
{
    freeList *p;
    p = (freeList *)malloc(sizeof(freeList));
    p->blockNumber = x;
    p->List = head;
    head = p;
    return head;
}
void add_at_Location(freeList *head,int location)
{
    int num,count = 1;
    freeList *prev,*q,*temp;
    temp = (freeList *)malloc(sizeof(freeList));
    printf("\nEnter the Data of Node: ");
    scanf("%d",&num);
    temp->blockNumber = num;
    temp->List = NULL;
    q = head;

while (q != NULL)
{
    if(count == location && count == 1 )
    {
        temp->List = q;
        head = temp;
    }
    if(count == location)
    {
        prev->List = temp;
        temp->List = q;   
        break;
    }
    else{
        count++;
        prev = q;
        q = q->List;
    }
}

}
freeList * delete(freeList *head,int x)
{
    freeList *temp,*temp2;
    temp = head;
    if(temp->blockNumber == x)   
    {
        head = head->List ;
        free(temp);
        temp = NULL;

    }
    else{
        while( (temp->blockNumber != x) && (temp->List != NULL))
        {
            temp2 = temp;
            temp = temp->List;   
        }
        if(temp->blockNumber == x)
        {
            temp2->List = temp->List;
            free(temp);
            temp = NULL;
        }
    }
    return (head);
}
