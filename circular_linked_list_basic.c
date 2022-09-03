#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * next;
};

void LL_traversal(struct node * head)
{
    struct node *ptr;
    ptr=head;
    do
    {
        printf("Element: %d\n",ptr->data);
        ptr=ptr->next;
    }while(ptr!=head);
}

void adding_to_ll(struct node *head,struct node *new,struct node *ptr)
{
    char ch;
    printf("Do u want to continue{y/n} ?: ");
    scanf("%s", &ch);
    while(ch=='y')
    {
        new=(struct node *)malloc(sizeof(struct node));
        printf("Enter the element: ");
        scanf("%d",&new->data);
        new->next=NULL;
        ptr->next=new;
        ptr=ptr->next;
        ptr->next=head;
        printf("Do u want to continue{y/n} ?: ");
        scanf("%s", &ch);
    }
}

int main()
{
    struct node *head,*ptr,*new;
    head=NULL;
    new=(struct node *)malloc(sizeof(struct node));
    printf("Enter the element: ");
    scanf("%d",&new->data);
    new->next=NULL;
    head=new;
    ptr=head;

    adding_to_ll(head,new,ptr);
    LL_traversal(head);
    return 0;
}