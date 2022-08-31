#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * next;
};

void adding_to_ll(struct node *head,struct node *new,struct node *ptr)
{
    char ch;
    printf("Do you want to continue? (y/n): ");
    scanf(" %s",&ch);
    while(ch=='y')
    {
        new=(struct node *)malloc(sizeof(struct node));
        printf("Enter the value: ");
        scanf("%d",&new->data);
        new->next=NULL;
        ptr->next=new;
        ptr=ptr->next;
        printf("Do you want to continue? (y/n): ");
        scanf(" %s",&ch);
    }
}

void ll_traversal(struct node *ptr)
{
    while(ptr!=NULL)
    {
        printf("Element: %d\n",ptr->data);
        ptr=ptr->next;
    }
}

void del_pos(struct node *head,int pos)
{
    int count=1;
    struct node *temp;
    struct node *ptr;
    ptr=head;
    while(ptr!=NULL && count!=pos-1)
    {
        ptr=ptr->next;
        count++;
    }
    temp=ptr;
    ptr->next=temp->next;
    free(temp);
}

void adding_to_ll(struct node *head,struct node *new,struct node *ptr);
void ll_traversal(struct node *ptr);
void del_pos(struct node *head,int pos);
int main()
{
    struct node *head,*ptr,*new;
    head=NULL;
    new=(struct node *)malloc(sizeof(struct node));
    printf("Enter the value: ");
    scanf("%d",&new->data);
    new->next=NULL;
    head=new;
    ptr=head;
    adding_to_ll(head,new,ptr);
    ll_traversal(ptr);
    del_pos(head,3);
    ll_traversal(ptr);
    return 0;
}