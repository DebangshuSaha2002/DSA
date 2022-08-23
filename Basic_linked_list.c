#include<stdio.h>

struct node 
{
    int data;
    struct node *next;
};
int main()
{
    struct node n1,n2,n3;
    n1.data=10;
    n1.next=&n2;
    n2.data=20;
    n2.next=&n3;
    n3.data=30;
    n3.next=NULL;

    struct node *head;
    head=&n1;
    struct node *ptr;
    ptr=head;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    return 0;
}