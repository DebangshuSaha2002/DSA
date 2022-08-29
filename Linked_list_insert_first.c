#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node *next;
};

void linked_list_traversal(struct node *ptr)
{
    while(ptr!=0)
    {
        printf("Element: %d\n",ptr->data);
        ptr=ptr->next;
    }
}
void insert_first(struct node *head)
{
    struct node *new;
    new=(struct node *)malloc(sizeof(struct node));
    printf("Enter value to be added at first: ");
    scanf("%d",&new->data);
    new->next=head;
    head=new;
    linked_list_traversal(head);
}
void adding_to_ll(struct node *head, struct node *ptr, struct node *new)
{
    char ch;
    printf("Do you want to add more? (Y/N): ");
    scanf("%s", &ch);
    while(ch=='y')
    {
        new=(struct node *)malloc(sizeof(struct node));
        printf("Enter the value: ");
        scanf("%d",&new->data);
        new->next=NULL;
        ptr->next=new;
        ptr=new;
        printf("Do you want to add more? (Y/N): ");
        scanf(" %c",&ch);
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
    linked_list_traversal(ptr);
    insert_first(head);

    return 0;
}