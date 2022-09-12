#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node * next;
}*head=NULL;

void traversal(struct node * ptr);

struct node * insert_first()
{
    struct node * new;
    struct node * ptr;
    new=(struct node *) malloc(sizeof(struct node));
    printf("Enter the value: ");
    scanf("%d",&new->data);
    new->next=head;
    head=new;
    ptr=head;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=new;
    ptr=head;
    printf("\nAfter inserting at first:\n");
    return ptr;
}

void adding_ll(struct node * ptr,struct node * new)
{
    char ch;
    printf("Do you want to continue(y/n)? :");
    scanf(" %c",&ch);
    while(ch=='y')
    {
        new=(struct node *)malloc(sizeof(struct node));
        printf("Enter the value: ");
        scanf("%d",&new->data);
        new->next=head;
        ptr->next=new;
        ptr=new;
        printf("Do you want to continue(y/n)? :");
        scanf(" %c",&ch);
    }
    traversal(ptr);
}

void traversal(struct node * ptr)
{
    ptr=head;
    do
    {
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }while(ptr!=head);
}

int main()
{
    struct node * ptr,*new;
    new=(struct node *)malloc(sizeof(struct node));
    printf("Enter the value: ");
    scanf("%d",&new->data);
    new->next=NULL;
    head=new;
    ptr=head;
    adding_ll(ptr,new);
    // traversal(ptr);
    insert_first();
    traversal(head);
    return 0;
}