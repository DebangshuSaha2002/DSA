#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node * next;
}*top;

void traversal();

void push()
{
    struct node * new;
    new=(struct node * )malloc(sizeof(struct node));
    printf("Enter a value: ");
    scanf("%d",&new->data);
    if(top==NULL)
    {
        top=new;
    }
    else
    {
        new->next=top;
        top=new;
    }
}

void pop()
{
    struct node * temp;
    temp=top;
    if(top==NULL)
    {
        printf("UNDERFLOW\n");
        exit(0);
    }
    else
    {
        top=top->next;
    }
    free(temp);
}

void traversal()
{
    while(top!=NULL)
    {
        printf("%d\n",top->data);
        top=top->next;
    }
}

int main()
{
    struct node * top,*new,*p,*q;
    top=NULL;
    push();
    push();
    push();
    // q=pop(p);
    traversal();
    return 0;
}