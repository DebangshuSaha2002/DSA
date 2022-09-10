#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node 
{
    char data;
    struct node * next;
}*top;

void push(char value)
{
    struct node * new=(struct node *)malloc(sizeof(struct node));
    new->data=value;
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
    struct node * temp=top;
    if(top==NULL)
    {
        printf("\nUNDERFLOW\n");
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
    top=NULL;
    // printf("Enter the length of the number: ");
    // scanf("%d",&n);
    char arr[]="135678";
    int n=strlen(arr);
    for(int i=0;i<n;i++)
    {
        push(arr[i]);
    }

    for(int i=0;i<n;i++)
    {
        pop();
    }
    return 0;
}