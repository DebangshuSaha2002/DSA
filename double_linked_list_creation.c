#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
}*head=NULL;

void insert_first();
void insert_pos();
void insert_last();
void del_first();
void del_last();
void del_pos();
void ll_traversal();

void ll_traversal()
{
    struct node *ptr;
    ptr=head;
    while(ptr!=NULL)
    {
        printf("Element: %d\n",ptr->data);
        ptr=ptr->next;
    }
}

void insert_last()
{
    printf("Insert at last:\n");
    struct node *new,*temp;
    struct node * last;
    char ch;
    int value;
    printf("Do you want to continue?: ");
    scanf("%s",&ch);
    while(ch=='y')
    {
        new=(struct node *)malloc(sizeof(struct node));
        printf("Enter the value: ");
        scanf("%d",&value);
        if(head==NULL)
        {
            new->next=NULL;
            new->prev=NULL;
            new->data=value;
            head=new;
        }
        else
        {
            temp=head;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            new->data=value;
            temp->next=new;
            new->prev=temp;
            new->next=NULL;
        }
        printf("Do u want to continue? (y/n): ");
        scanf("%s",&ch);
    }
    ll_traversal();
}

void insert_first()
{
    printf("Insert at first:\n ");
    char ch;
    int value;
    struct node *new;
    printf("Do u want to continue? (y/n): ");
    scanf("%s",&ch);
    while(ch=='y')
    {
        new=(struct node *)malloc(sizeof(struct node));
        printf("Enter the value: ");
        scanf("%d",&value);
        if(head==NULL)
        {
            new->next = NULL;
            new->prev=NULL;    
            new->data=value;
            head=new;
        }
        else
        {
            new->data=value;
            new->prev=NULL;
            new->next=head;
            head->prev=new;
            head=new;
        }
        printf("Do u want to continue? (y/n): ");
        scanf("%s",&ch);
    }
    ll_traversal();
}

void insert_pos()
{
    int count=1;
    struct node *new,*ptr;
    int value,pos;
    ptr=head;
    printf("Inserting at a position: \n");
    printf("\nEnter the postion: ");
    scanf("%d",&pos);
    printf("\nEnter the value: ");
    scanf("%d",&value);
    new=(struct node *)malloc(sizeof(struct node));
    new->data=value;
    while(ptr!=NULL && count!=pos-1)
    {
        ptr=ptr->next;
        count++;
    }
    new->next=ptr->next;
    new->prev=ptr;
    ptr->next->prev=new;
    ptr->next=new;
    ll_traversal();
}

void del_first()
{
    struct node * ptr;
    ptr=head;
    if(head==NULL)
    {
        printf("Deletion not possible\n");
        exit(0);
    }
    else
    {
        head=head->next;
        head->prev=NULL;
        free(ptr);
    }
    printf("\nDeleting the data at the first position:\n");
    ll_traversal();
}

void del_last()
{
    struct node * ptr, *temp;
    ptr=head;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    temp=ptr;
    ptr=ptr->prev;
    ptr->next=NULL;
    free(temp);
    printf("\nDeleting the data at the last position:\n");
    ll_traversal();
}

void del_pos()
{
    int pos,count=1;
    printf("\nEnter the position to delete: ");
    scanf("%d",&pos);
    printf("\nDeleting at position %d\n",pos);
    struct node * ptr,*temp;
    ptr=head;
    while(ptr!=NULL && count!=pos-1)
    {
        ptr=ptr->next;
        count++;
    }
    temp=ptr->next;
    ptr->next=temp->next;
    temp->next->prev=ptr;
    free(temp);
    ll_traversal();
}

int main()
{
    struct node *new;
    struct node *ptr;
    // new=(struct node *)malloc(sizeof(struct node));
    // printf("Enter the value: ");
    // scanf("%d",&new->data);
    // new->next=NULL;
    // new->prev=NULL;
    // head=new;
    // ptr=head;
    insert_first();
    insert_last();
    insert_pos();
    del_first();
    del_last();
    del_pos();
    // insert_last(head);
    //reverse(head);
    return 0;
}