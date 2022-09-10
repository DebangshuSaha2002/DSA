#include<stdio.h>
#include<stdlib.h>

int top;
int maxsize;
int n;
int stack[100];

void push();
void pop();
void display();
int main()
{
    top=-1;
    int choice;
    printf("Enter the maxsize of stack: ");
    scanf("%d",&maxsize);
    printf("1:PUSH\n2:POP\n3:Display Stack\n4.Exit\n");
    int i=0;
    do{
    printf("Enter your choice: ");
    scanf("%d",&choice);
    
        switch (choice)
        {
            case 1:
            {
                push();
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
                printf("EXIT\n");
                break;
            }
            default:
            {
                printf("Enter a valid choice\n");
            }
        }
    }while(choice!=5);
    return 0;
}


void push()
{
    if(top>=maxsize-1)
    {
        printf("\nOVERFLOW\n");
    }
    else
    {
        printf("Enter the number to enter in stack: ");
        scanf("%d",&n);
        top++;
        stack[top]=n;
    }
}

void pop()
{
    if(top<=-1)
    {
        printf("\nUNDERFLOW\n");
    }
    else
    {
        printf("\nThe popped element is: %d\n",stack[top]);
        top--;
    }
}

void display()
{
    if(top>=0)
    {
        printf("The elements in the stack is: \n");
        for(int i=top;i>=0;i--)
        {
            printf("Element: %d\n",stack[i]);
        }

    }
    else{
        printf("Stack Empty");
    }
}
