#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};

void ll_traversal(struct node *ptr);

void del_first(struct node *head)
{
    struct node *ptr;
    ptr=head;
    if(head==NULL)
    {
        printf("Deletion not possible ");
        exit(0);
    }
    head=head->next;
    free(ptr);
    printf("\n");
    ll_traversal(head);
}

void ll_traversal(struct node *ptr)
{
    while(ptr!=NULL)
    {
        printf("Element: %d\n",ptr->data);
        ptr=ptr->next;
    }
}

void add_to_ll(struct node *head,struct node *ptr,struct node *new)
{
    char ch;
    printf("Do u want to continue (Y/N) : ");
    scanf(" %s",&ch);
    while(ch=='y')
    {
        new=(struct node *)malloc(sizeof(struct node));
        printf("Enter the value: ");
        scanf("%d",&new->data);
        new->next=NULL;
        ptr->next=new;
        ptr=new;
        printf("Do u want to continue (Y/N) : ");
        scanf(" %s",&ch);
    }
}

int main()
{
    struct node *new;
    struct node *head;
    struct node *ptr;
    head=NULL;
    new=(struct node *)malloc(sizeof(struct node));
    printf("Enter the value: ");
    scanf("%d",&new->data);
    new->next=NULL;
    head=new;
    ptr=head;
    add_to_ll(head,ptr,new);
    ll_traversal(ptr);
    del_first(head);
    return 0;
}