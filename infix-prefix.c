#include<stdio.h>
#include<ctype.h>
#include<string.h>

char stack[100];
int top=-1;
char pre[20];
char in[20];

void push(char x)
{
    stack[++top]=x;
}

int pop()
{
    if(top==-1)
    {
        return -1;
    }
    else
    {
        return stack[top--];
    }
}

int priority(char x)
{
    if(x=='(')
    {
        return 0;
    }
    if(x=='+' || x=='-')
    {
        return 1;
    }
    if(x=='*' || x=='/')
    {
        return 2;
    }
    if(x=='^')
    {
        return 3;
    }
    return 0;
}

void revstr(char x[])
{
    int temp;
    int len=strlen(x);
    for(int i=0;i<len/2;i++)
    {
        temp=x[i];
        x[i]=x[len-i-1];
        x[len-i-1]=temp;
    }
} 

void infixtoprefix(char infix[20],char prefix[20])
{
    char temp,x;
    // char in[20];
    int i=0,j=0;
    int len=strlen(infix);
    revstr(infix);
    while(infix[i]!='\0')
    {
        temp=infix[i];
        if(isalnum(temp))
        {
            prefix[j++]=temp;
        }
        else if(temp==')')
        {
            push(temp);
        }
        else if(temp=='(')
        {
            while((x=pop())!=')')
            {
                prefix[j++]=x;
            }
        }
        else
        {  
            while(priority(stack[top])>=priority(temp))
            {
                prefix[j++]=pop();
            }
            push(temp);
        }
        i++;
    }
    while(top!= -1)
    {
    prefix[j++]=pop();
    }
    prefix[j]='\0'; 
    revstr(prefix);
}
int main()
{
    char infix[20],prefix[20];
    printf("Enter the infix expression\n");
    scanf("%s",infix);
    printf("The infix expression is %s\n",infix);
    infixtoprefix(infix, prefix);
    printf("The prefix expression is %s\n",prefix);
}