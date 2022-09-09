#include<stdio.h>
#include<stdlib.h>

int stack[100];
int top;
int maxsize;
int value;
void push()
{
    if(top>=maxsize-1)
    {
        printf("\nOVERFLOW\n");
        exit(0);
    }
    else
    {
        printf("Enter value into the stack: ");
        scanf("%d",&value);
        top++;
        stack[top]=value;
    }
}

void pop()
{
    if(top==-1)
    {
        printf("\nUNDERFLOW\n");
    }
    else
    {
        printf("The popped element is: %d\n",stack[top]);
        top--;
    }
}

void display()
{
    if(top>=0)
    {
        printf("The element in the stack is:\n");
        for(int i=top;i>=0;i--)
        {
            printf("Element: %d\n",stack[i]);
        }
    }
}

int main()
{
    top=-1;
    printf("Enter the maxsize:");
    scanf("%d",&maxsize);
    push();
    push();
    push();
    push();
    push();
    pop();
    display();
    return 0;
}