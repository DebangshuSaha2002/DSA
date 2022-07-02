#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

//Traversing the circular linked list
void traversal_circular(struct node *head)
{
    struct node *ptr=head;
    do
    {
        printf("Element : %d \n",ptr->data);
        ptr=ptr->next;

    }while(ptr!=head);    
}

//Inserting in the circular linked list at the first place

struct node *insertatfirst(struct node *head,int data)
{
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=data;
    struct node *p=head->next;
    while(p->next !=head)
    {
        p=p->next;
    }
    p->next=ptr;
    ptr->next=head;
    head=ptr;
    return head;
}

int main()
{
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;

    head=(struct node *)malloc(sizeof(struct node));
    second=(struct node *)malloc(sizeof(struct node));
    third=(struct node *)malloc(sizeof(struct node));
    fourth=(struct node *)malloc(sizeof(struct node));

    head->data=7;
    head->next=second;

    second->data=3;
    second->next=third;

    third->data=9;
    third->next=fourth;

    fourth->data=11;
    fourth->next=head;

    //Calling function for traversing the circular linked list
    printf("Before inserting \n");
    traversal_circular(head);

    head=insertatfirst(head,67);
    printf("After inserting \n");
    traversal_circular(head);
    return 0;
}