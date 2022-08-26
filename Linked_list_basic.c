#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void insert_at_node(struct node *head,int data,int index)
{
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    struct node *p=(struct node *)malloc(sizeof(struct node));
    p=head;
    int i=0;
    while(i!=index-1)
    {
        p=p->next;
        i++;
    }
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;
}

void linkedListTraversal(struct node* ptr)
{
    while(ptr!=NULL)
    {
        printf("Element: %d \n", ptr->data);
        ptr=ptr->next;
    }
}


void adding_tothe_ll(struct node *ptr,struct node *head, struct node *new)
{
    char ch;
    printf("Do you want to add (y,n) \n");
    scanf(" %c",&ch);
    while(ch=='y')
    {
        new=(struct node *)malloc(sizeof(struct node));
        printf("Enter the new value: \n");
        scanf("%d",&new->data);
        new->next=NULL;
        ptr->next=new;
        ptr=new;
        printf("Do you want to add more values? (y,n) \n");
        scanf(" %c",&ch);
    }
}

int main()
{
    struct node *head;
    struct node *new;
    struct node *ptr;
    head=NULL;

    new=(struct node *)malloc(sizeof(struct node));
    printf("Enter the value: \n");
    scanf("%d",&new->data);
    new->next=NULL;
    head=new;
    ptr=head;

    adding_tothe_ll(ptr,head,new);
    linkedListTraversal(ptr);
    insert_at_node(head,101,2);
    printf("\n");
    linkedListTraversal(ptr);
    return 0;
}

