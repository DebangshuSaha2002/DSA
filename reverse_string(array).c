#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char stack[100];
int top;

void push(char c)
{
    if(top==100)
    {
        printf("OVERFLOW\n");
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
        printf("UNDERFLOW\n");
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
    char str[]="Debangshu";
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