#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void linkedlisttraversal(struct node * ptr)
{
    while(ptr!=NULL)
    {
        printf("Element :%d \n",ptr->data);
        ptr=ptr->next;
    }
}

//Deleting the first node
struct node * deleteatindex(struct node *head,int index)
{
    struct node *p=head;
    struct node *q=head->next;
    for(int i=0;i<(index-1);i++)
    {
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    free(q);
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

    fifth->data=21;
    fifth->next=NULL;
    printf("Before inserting value \n");
    linkedlisttraversal(head);

    //head=deletefirst(head);
    head=deleteatindex(head,2);
    printf("After inserting value \n");
    linkedlisttraversal(head);
    return 0;
}
