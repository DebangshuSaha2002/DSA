#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node 
{
    char data;
    struct node * next;
}*top;

void push(char c)
{
    struct node * new=(struct node *)malloc(sizeof(struct node));
    new->data=c;
    if(top==NULL)
    {
        new->next=NULL;
    }
    else
    {
        new->next=top;
    }
    top=new;
}

void pop()
{
    struct node *temp;
    temp=top;
    if(top==NULL)
    {
        printf("UNDERFLOW\n");
    }
    else
    {
        top=top->next;
        printf("%s",&temp->data);
        free(temp);
    }
}

int main()
{
    int n;
    // printf("Enter the length of your name: ");
    // scanf("%d",&n);
    char str[]="Debangshu";
    n=strlen(str);
    int i;
    for(i=0;i<n;i++)
    {
        push(str[i]);
    }

    for(i=0;i<n;i++)
    {
        pop();
    }
    return 0;
}