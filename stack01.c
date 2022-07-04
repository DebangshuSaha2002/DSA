#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr; 
};

int isEmpty(struct stack *ptr)
{
    if(ptr->top==-1)
    {
        return 1;
    }
    return 0;
}

int isFull(struct stack *ptr)
{
    if(ptr->top==ptr->size-1)
    {
        return 1;
    }
    return 0;
}

int main()
{
    struct stack *s;
    s->size=80;
    s->top=-1;
    s->arr=(int *)malloc(s->size * sizeof(int));
    //Adding values to stack manually

    s->arr[0]=7;
    s->top++;

    if(isEmpty(s))
    {
        printf("The stack is Empty\n ");
    }
    else
    printf("The stack is not empty\n ");
    return 0;
}