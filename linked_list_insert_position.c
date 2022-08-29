#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node * next;
};

void ll_traversal(struct node *ptr)
{
    while(ptr!=NULL)
    {
        printf("Element:%d\n",ptr->data);
        ptr=ptr->next;
    }
}

void insert_pos(struct node *head,int pos)
{
    struct node *new;
    new=(struct node *)malloc(sizeof(struct node));
    struct node *ptr;
    ptr=(struct node *)malloc(sizeof(struct node));

    printf("Enter a value: ");
    scanf("%d",&new->data);
    ptr=head;
    int count=1;
    while (ptr!=NULL && count!=pos-1)
    {
        ptr=ptr->next;
        count+=1;
    }
    new->next=ptr->next;
    ptr->next=new;
    ll_traversal(head);
}
void adding_to_ll(struct node *head,struct node *ptr,struct node *new)
{
    
    char ch;
    printf("Do you want to add more values(y/n): ");
    scanf(" %s",&ch);
    while(ch=='y')
    {
        new=(struct node *)malloc(sizeof(struct node));
        printf("Enter a value: ");
        scanf("%d",&new->data);
        new->next=NULL;
        ptr->next=new;
        ptr=new;
        printf("Do you want to add more values(y/n): ");
        scanf(" %s",&ch);
    }
}
int main()
{
    struct node *head,*ptr,*new;

    head=NULL;
    int val;
    new=(struct node *)malloc(sizeof(struct node));
    printf("Enter the value: ");
    scanf("%d",&new->data);
    new->next=NULL;
    head=new;
    ptr=head;
    adding_to_ll(head,ptr,new);
    ll_traversal(ptr);
    printf("\n");
    insert_pos(head,2);
}