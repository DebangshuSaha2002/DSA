#include<stdio.h>
#include<stdlib.h>

int top;
int maxsize;
char name;
char stack[100];
char ch;

void push()
{
    if(top==maxsize)
    {
        printf("OVERFLOW\n");
        exit(0);
    }
    else
    {
        printf("Do you want to cont(y/n)? :");
        scanf(" %c",&ch);
        while(ch=='y')
        {
            printf("Enter the alphabets in your name: ");
            scanf(" %c",&name);
            top++;
            stack[top]=name;
            printf("Do you want to cont(y/n)? :");
            scanf(" %c",&ch);
        }
    }
}

void pop()
{
    if(top==-1)
    {
        printf("UNDERFLOW");
    }
    else
    {
        while(top!=0)
        {
            printf("%c",stack[top]);
            top--;
        }
    }
}

int main()
{
    top=-1;
    printf("Enter the maxsize: ");
    scanf("%d",&maxsize);
    push();
    pop();
    return 0;
}
