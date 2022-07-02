#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * next;
};

void linklisttraversal(struct node *ptr)
{
    while(ptr!=NULL)
    {
        printf("Element : %d \n",ptr->data);
        ptr=ptr->next;
    }
}

struct node * deletevalue(struct node *head,int value)
{
    struct node * p=head;
    struct node *q=head->next;
    while(q->data!=value)
    {
        p=p->next;
        q=q->next;
    }
    if(q->data==value)
    {
        p->next=q->next;
        free(q);
    }
    return head;
}

int main()
{
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;
    struct node *fifth;

    head=(struct node *)malloc(sizeof(struct node));
    second=(struct node *)malloc(sizeof(struct node));
    third=(struct node *)malloc(sizeof(struct node));
    fourth=(struct node *)malloc(sizeof(struct node));
    fifth=(struct node *)malloc(sizeof(struct node));

    head->data=7;
    head->next=second;

    second->data=36;
    second->next=third;

    third->data=9;
    third->next=fourth;

    fourth->data=3;
    fourth->next=fifth;

    fifth->data=26;
    fifth->next=NULL;

    printf("Before inserting \n");
    linklisttraversal(head);

    head=deletevalue(head,36);

    printf("After inserting \n");
    linklisttraversal(head);
    return 0;
}