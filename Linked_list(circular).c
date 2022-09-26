#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node * next;
}*head=NULL;

void printing()
{
    struct node * ptr;
    ptr=head;
    do
    {
        printf("Element : %d\n",ptr->data);
        ptr=ptr->next;
    }while(ptr!=head);
}

void insert_first()
{
    struct node * new, * ptr;
    new=(struct node *)malloc(sizeof(struct node));
    printf("Enter a value:");
    scanf("%d",&new->data);
    if(head==NULL)
    {
        head=new;
    }
    else
    {
        new->next=head;
        head=new;
        ptr=head;
        do
        {
            ptr=ptr->next;
        }while(ptr->next!=head);
        ptr->next=head;
        // head=new;
        printing();
    }
}

void insert_atpos()
{
    int pos,count=1;
    struct node * new;
    struct node * ptr=head;
    new=(struct node *)malloc(sizeof(struct node));
    printf("\nEnter the position where you want to insert value: ");
    scanf("%d",&pos);
    printf("\nEnter a value:");
    scanf("%d",&new->data);
    do
    {
        ptr=ptr->next;
        count+=1;
    }while(ptr!=head && count!=pos-1);
    new->next=ptr->next;
    ptr->next=new;
    // printing();
}

int main()
{
    struct node * new,* ptr;
    new=(struct node *)malloc(sizeof(struct node));
    printf("Enter a value:");
    scanf("%d",&new->data);
    new->next=head;
    head=new;
    ptr=head;
    
    insert_first();
    insert_first();
    insert_first();
    // printing();
    insert_atpos();
    insert_atpos();
    // printing();
    return 0;
}