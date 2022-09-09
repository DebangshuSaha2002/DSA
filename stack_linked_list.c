#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node * next;
}*top=NULL;

void printing(struct node * ptr)
{
    while(ptr!=NULL)
    {
        printf("Element : %d\n",ptr->data);
        ptr=ptr->next;
    }
}

void push()
{
    struct node *new;
    new=(struct node *)malloc(sizeof(struct node));
    char ch;
    printf("Do you want to add more to stack: ");
    scanf(" %c",&ch);
    while(ch=='y')
    {
        printf("Enter value to be added at first: ");
        scanf("%d",&new->data);
        if(top==NULL)
        {
            top=new;
        }
        top->next=new->next;
        top=new;
        printf("Do you want to add more to stack: ");
        scanf(" %c",&ch);
    }
    printing(top);
}

int main()
{
    push();
    return 0;
}

