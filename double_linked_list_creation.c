#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
}*head=NULL;

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

// void reverse(struct node * head)
// {
//     struct node *ptr;
//     ptr=head;
//     while(ptr!=NULL)
//     {
//         ptr=ptr->next;
//     }

//     while(ptr!=NULL)
//     {
//         printf("Element: %d\n",ptr->data);
//         ptr=ptr->prev;
//     }
//     ll_traversal();
// }


// struct node * traverse_last(struct node *head)
// {
//     struct node *ptr;
//     ptr=head;
//     struct node *tail;
//     tail=ptr;
//     int x;
//     while(tail->next!=NULL)
//     {
//         tail=tail->next;
//     }
//     return tail;
// }

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

void insert_pos(int pos)
{
    int count=1;
    struct node *new,*ptr;
    int value;
    printf("Inserting at a position: \n");
    printf("Enter the value: ");
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
    int n;
    printf("\nEnter the postion: ");
    scanf("%d",&n);
    insert_pos(n);
    // insert_last(head);
    //reverse(head);
    return 0;
}