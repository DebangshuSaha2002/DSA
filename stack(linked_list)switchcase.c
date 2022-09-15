#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * next;
}*top;

void push(int value)
{
    struct node * new;
    new=(struct node * )malloc(sizeof(struct node));
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
        printf("UNDERFLOW\n ");
        exit(0);
    }
    else
    {
        top=top->next;
        printf("The popped element is : %d",temp->data);
        free(temp);
    }
}

void display()
{
    while(top!=NULL)
    {
        printf("Element:%d\n",top->data);
        top=top->next;
    }
}

int main()
{
    // struct node * top;
    top=NULL;
    int value;
    int choice;
    printf("\n1.PUSH\n2.POP\n3.Display Stack\n4.Exit\n");
    do
    {
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
        {
            printf("Enter a value: ");
            scanf("%d",&value);
            push(value);
            break;
        }
        case 2:
        {
            pop();
            break;
        }
        case 3:
        {
            display();
            break;
        }
        case 4:
        {
            printf("EXIT");
            break;
        }
        default:
        {
            printf("\nWrong choice\n");
        }
        }
    } while (choice!=4);
    return 0;
}