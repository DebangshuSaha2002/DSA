#include<stdio.h>
int top1=-1;
int maxsize=6;
int top2=6;
int stack[6];

void push_in_one()
{
    if(top1+1==top2)
    {
        printf("\nOverflow\n");
        return;
    }
    else
    {
        int num;
        printf("Enter the number: ");
        scanf("%d",&num);
        stack[++top1]=num;
        return;
    }
}

void pop_in_one()
{
    if(top1==-1)
    {
        printf("\nUnderflow\n");
        return;
    }
    else
    {
        printf("The deleted element is: %d",stack[top1]);
        --top1;
        return;
    }
}

void push_in_two()
{
    if(top1+1==top2)
    {
        printf("\nOverflow\n");
        return;
    }
    else
    {
        int num1;
        printf("Enter the number: ");
        scanf("%d",&num1);
        stack[--top2]=num1;
        return;
    }
}

void pop_in_two()
{
    if(top2==-1)
    {
        printf("\nUnderflow\n");
        return;
    }
    else
    {
        printf("The deleted element is: %d",stack[top2]);
        ++top2;
        return;
    }
}

void display_one()
{
    if(top1==-1)
    {
        printf("EMPTY STACK\n");
        return;
    }
    for(int i=top1;i>=0;i--)
    {
        printf("%d ",stack[i]);
    }
    printf("\n");
}

void display_two()
{
    if(top2==maxsize)
    {
        printf("EMPTY STACK\n");
        return;
    }
    for(int i=top2;i<maxsize;i++)
    {
        printf("%d ",stack[i]);
    }
    printf("\n");
}

int main()
{
    int op;
    printf("\n1:Push in stack 1\n2:Pop from stack 1\n3:Display stack 1");
    printf("\n1:Push in stack 2\n2:Pop from stack 2\n3:Display stack 2");
    int i=0;
    while(i!=1)
    {
        printf("\nEnter your choice: ");
        scanf("%d",&op);
        switch (op)
        {
            case 1:
            {
                push_in_one();
                break;
            }
            case 2:
            {
                pop_in_one();
                break;
            }
            case 3:
            {
                display_one();
                break;
            }
            case 4:
            {
                push_in_two();
                break;
            }
            case 5:
            {
                pop_in_two();
                break;
            }
            case 6:
            {
                display_two();
                break;
            }
            default:
            {
                i=1;
            }
        }
    }
    return 0;
}