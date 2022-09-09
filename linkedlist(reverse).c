#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node * next;
};

void traversal(struct node * ptr)
{
    while(ptr!=NULL)
    {
        printf("Element: %d\n",ptr->data);
        ptr=ptr->next;
    }
}

struct node * reverse(struct node * head)
{
    struct node * p;
    struct node * q;
    p=head->next;
    q=p->next;
    head=NULL;
    while(q!=NULL)
    {
        p->next=head;
        head=p;
        p=q;
        q=q->next;
    }
    p->next=head;
    head=p;
    return head;
}

void add_to_ll(struct  node * head,struct node * new,struct node * ptr)
{
    char ch;
    printf("Do you want to continue(y/n)? : ");
    scanf(" %c",&ch);
    while(ch=='y')
    {
        new=(struct node *)malloc(sizeof(struct node));
        printf("Enter the value: ");
        scanf("%d",&new->data);
        new->next=NULL;
        ptr->next=new;
        ptr=ptr->next;
        printf("Do you want to continue(y/n)? : ");
        scanf(" %c",&ch);
    }
};

int main()
{
    struct node * head, *new, *ptr,*ptr1;
    head=NULL;
    new=(struct node *)malloc(sizeof(struct node));
    printf("Enter the value : ");
    scanf("%d",&new->data);
    new->next=NULL;
    head=new;
    ptr=head;
    add_to_ll(head,new,ptr);
    traversal(head);

    printf("Reversing: \n");
    ptr1=reverse(head);
    traversal(ptr1);
    return 0;
}