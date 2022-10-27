#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
}*head=NULL;


void insert_last();

void ll_traversal()
{
    struct node *ptr;
    ptr=head;
    do
    {
        printf("Element: %d\n",ptr->data);
        ptr=ptr->next;
    }while(ptr!=head);
}

void ll_reverse()
{
    struct node * ptr=head;
    while(ptr->next!=head)
    {
        ptr=ptr->next;
    }

    while(ptr!=head)
    {
        printf("%d\n",ptr->data);
        ptr=ptr->prev;
    }
    printf("%d\n",ptr->data);
}

void insert_last()
{
    printf("Insert at last:\n");
    struct node *new,*temp;
    char ch;
    int value;
    printf("Do you want to continue?: ");
    scanf("%s",&ch);
    while(ch=='y')
    {
        new=(struct node *)malloc(sizeof(struct node));
        printf("Enter the value: ");
        scanf("%d",&value);
        new->data=value;
        if(head==NULL)
        {
            head=new;
            new->next=head;
            new->prev=head;
        }
        else
        {
            new->prev=head->prev;
            (head->prev)->next=new;
            head->prev=new;
            new->next=head;
        }
        printf("Do u want to continue? (y/n): ");
        scanf("%s",&ch);
    }
    ll_traversal();
    printf("\nNow in reverse\n");
    ll_reverse();
}

int main()
{
    int choice;
    printf("\nDOUBLE CIRCULAR LINKED LIST OPERATIONS:\n");
    printf("\n1:Insert at last\n");
    int i=0;
    while(i!=1)
    {
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch (choice)
        {
            case 1:
            {
                insert_last();
                printf("\n");
                break;
            }
            default:
            {
                i=1;
            }
        }
    }
    return 0;
}

