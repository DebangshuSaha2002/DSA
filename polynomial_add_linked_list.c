//Adding polynomials using linked list

#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int co;
    int ex;
    struct node * next;
};

void create(struct node *head)
{
    head=NULL;
    char ch;
    struct node *new,*ptr;
    new=(struct node *)malloc(sizeof(struct node));
    printf("Enter the coefficient and the exponential value: ");
    scanf("%d%d",&new->co,&new->ex);
    new->next=NULL;
    head=new;
    ptr=head;
    printf("Do you want to continue (y/n)? : ");
    scanf(" %s",&ch);
    while(ch=='y')
    {
        new=(struct node *)malloc(sizeof(struct node));
        printf("Enter the coefficient and the exponential value: ");
        scanf("%d%d",&new->co,&new->ex);
        new->next=NULL;
        ptr->next=new;
        ptr=ptr->next;
        printf("Do you want to continue (y/n)? : ");
        scanf(" %s",&ch);
    }
}


struct node *insert(struct node *head3,int ex,int co)
{
    struct node *ptr;
    struct node *new;
    new=(struct node *)malloc(sizeof(struct node));
    new->ex=ex;
    new->co=co;
    new->next=NULL;
    if(head3==NULL)
    {
        head3=new;
    }
    else{
        ptr=head3;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=NULL;
        new->next=NULL;
    }
    return (head3);
}

void polyadd(struct node *head1,struct node *head2,struct node *head3)
{
    struct node *ptr1,*ptr2;
    ptr1=head1;
    ptr2=head2;
    while(ptr1!=NULL && ptr2!=NULL)
    {
        if(ptr1->ex == ptr2->ex)
        {
            head3=insert(head3,ptr1->ex,ptr1->co+ptr2->co);
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        else if(ptr1->ex < ptr2->ex)
        {
            head3=insert(head3,ptr2->ex,ptr1->co+ptr2->co);
            ptr2=ptr2->next;
        }
        else
        {
            head3=insert(head3,ptr1->ex,ptr1->co+ptr2->co);
            ptr1=ptr1->next;
        }
        while(ptr2!=NULL)
        {
            head3=insert(head3,ptr2->ex,ptr2->co);
            ptr2=ptr2->next;
        }
        while(ptr1!=NULL)
        {
            head3=insert(head3,ptr1->ex,ptr1->co);
            ptr1=ptr1->next;
        }
    }
    // return head3;
}

void display(struct node *head)
{
    struct node *ptr;
    ptr=head;
    while(ptr!=NULL)
    {
        printf("%d x^%d +",ptr->co,ptr->ex);
    }
}

int main()
{
    struct node *head1;
    struct node *head2,*poly;
    printf("For polynomial 1: \n");
    create(head1);
    printf("\nFor polynomial 2: \n");
    create(head2);
    poly=(struct node *)malloc(sizeof(struct node));
    printf("\nNow adding the 2 polynomials: \n");
    polyadd(head1,head2,poly);
    display(poly);
    return 0;
}
