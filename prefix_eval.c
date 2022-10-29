//Simple prefix evaluation

//Prefix Evaluation
//POstfix evaluation using for loop

#include<stdio.h>
#include<ctype.h>
#include<string.h>

int stack[20];
int top=-1;

void push(int x)
{
    stack[++top]=x;
}

int pop()
{
    return stack[top--];
}

int main()
{
    char exp[20];
    int n,n1,n2,n3;
    printf("Enter the prefix expression: ");
    scanf("%s",exp);

    for(int i=(strlen(exp)-1);i>=0;i--)
    {
        if(exp[i]=='+')
        {
            n1=pop();
            n2=pop();
            n3=n2+n1;
            push(n3);
        }
        else if(exp[i]=='-')
        {
            n1=pop();
            n2=pop();
            n3=n2-n1;
            push(n3);
        }
        else if(exp[i]=='*')
        {
            n1=pop();
            n2=pop();
            n3=n2*n1;
            push(n3);
        }
        else if(exp[i]=='/')
        {
            n1=pop();
            n2=pop();
            n3=n2/n1;
            push(n3);
        }
        else if(exp[i]=='^')
        {
            n1=pop();
            n2=pop();
            n3=n2^n1;
            push(n3);
        }
        else
        {
            n=exp[i]-48;
            push(n);
        }
    }
    printf("The result of the exp %s is %d\n",exp,pop());
    return 0;
}