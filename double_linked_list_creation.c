#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
}*head=NULL;

void ll_traversal(struct node *ptr)
{
    ptr=head;
    while(ptr!=NULL)
    {
        printf("Element: %d\n",ptr->data);
        ptr=ptr->next;
    }
}

void reverse()
{
    struct node *ptr;
    ptr=head;
    while(ptr!=NULL)
    {
        ptr=ptr->next;
    }

    while(ptr!=NULL)
    {
        printf("Element: %d\n",ptr->data);
        ptr=ptr->prev;
    }
    ll_traversal(ptr);
}

void add_to_double_ll(struct node *ptr,struct node *new)
{
    char ch;
    printf("Do u want to continue? (y/n): ");
    scanf("%s",&ch);
    while(ch=='y')
    {
        new=(struct node *)malloc(sizeof(struct node));
        printf("Enter the value: ");
        scanf("%d",&new->data);
        new->prev=NULL;
        new->next=head;
        head=new;
        printf("Do u want to continue? (y/n): ");
        scanf("%s",&ch);
    }
    ll_traversal(head);
}

int main()
{
    struct node *new;
    struct node *ptr;
    new=(struct node *)malloc(sizeof(struct node));
    printf("Enter the value: ");
    scanf("%d",&new->data);
    new->next=NULL;
    new->prev=NULL;
    head=new;
    ptr=head;
    add_to_double_ll(ptr,new);
    reverse();
    return 0;
}