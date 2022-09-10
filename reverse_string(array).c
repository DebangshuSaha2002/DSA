#include<stdio.h>
#include<string.h>

int top;
int maxsize=100;
char stack[100];

void push(char c)
{
    if(top>=maxsize)
    {
        printf("OVERFLOW");
    }
    else
    {
        top++;
        stack[top]=c;
    }
}

void pop()
{
    if(top==-1)
    {
        printf("\nUNDERFLOW");
    }
    else
    {
        printf("%c",stack[top]);
        top--;
    }
}

int main()
{
    top=-1;
    char str[]="HelloWorld";
    int len=strlen(str);

    for(int i=0;i<len;i++)
    {
        push(str[i]);
    }
    for(int i=0;i<len;i++)
    {
        pop();
    }
    return 0;
}