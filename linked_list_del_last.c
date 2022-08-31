#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};

void ll_traversal(struct node * ptr)
{
    while(ptr!=NULL)
    {
        printf("Element: %d\n",ptr->data);
        ptr=ptr->next;
    }
}

void del_last (struct node * head)
{
    struct node * ptr;
    struct node * temp;
    ptr=head;
    // if(head==NULL)
    // {
    //     printf("Not possible to delete");
    //     exit(0);
    // }
    
    while((ptr->next)->next!=NULL)
    {
        ptr=ptr->next;
    }
    // temp=ptr->next;
    ptr->next=NULL;
    // free(temp);
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
        ptr=ptr->next;
        printf("Do u want to continue (Y/N) : ");
        scanf(" %s",&ch);
    }
}

int main()
{
    struct node *head,*ptr,*new;
    head=NULL;
    new=(struct node *)malloc(sizeof(struct node));
    printf("Enter a value: ");
    scanf("%d",&new->data);
    new->next=NULL;
    head=new;
    ptr=head;
    add_to_ll(head,ptr,new);
    ll_traversal(ptr);
    del_last(head);
    printf("\nAfter deleting the last element: \n");
    ll_traversal(ptr);
    return 0;
}