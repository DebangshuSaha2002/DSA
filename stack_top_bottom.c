#include<stdio.h>
#include<stdlib.h>

struct stack{
    int top;
    int size;
    int *arr;
};

int isEmpty(struct stack *ptr)
{
    if(ptr->top==-1)
    return 1;
    else
    return 0;
}

int isFull(struct stack *ptr)
{
    if(ptr->top==ptr->size-1)
    return 1;
    else
    return 0;
}

void push(struct stack *ptr,int data)
{
    if(isFull(ptr))
    {
        printf("Stack Overflow \n");
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top]=data;
    }
}

int pop(struct stack *ptr)
{
    if(isEmpty(ptr))
    {
        printf("Stack Underflow \n");
        return -1;
    }
    else{
        int value=ptr->arr[ptr->top];
        ptr->top--;
        return value;
    }
}

int peek(struct stack *ptr,int i)
{
    int arrayind=ptr->top-i-1;
    if(arrayind<0)
    {
        printf("Invalid entry \n");
        return -1;
    }
    else{
        return ptr->arr[arrayind];
    }
}

int stackTop(struct stack *ptr)
{
    return ptr->arr[ptr->top];
}

int stackBottom(struct stack *ptr)
{
    return ptr->arr[0];
}

int main()
{
    struct stack *ptr=(struct stack *)malloc(sizeof(struct stack));
    ptr->size=50;
    ptr->top=-1;
    ptr->arr=(int *)malloc(ptr->size * sizeof(int));

    printf("Stack has been created successfully \n");

    printf("Before pushing, Full: %d \n",isFull(ptr));
    printf("Before pushing, Empty: %d \n",isEmpty(ptr));

    push(ptr,1);
    push(ptr,12);
    push(ptr,76);
    push(ptr,87);
    push(ptr,10);
    push(ptr,34);
    push(ptr,23);
    push(ptr,100);
    push(ptr,69);
    push(ptr,79);
    push(ptr,33); 
    pop(ptr);

    printf("The top_most value of the stack is %d \n",stackTop(ptr));
    printf("The Bottom_most value of the stack is %d \n",stackBottom(ptr));
    return 0;
}