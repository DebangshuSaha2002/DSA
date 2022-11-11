#include<stdio.h>
int front=-1;
int rear=-1;
int size=5;
int queue[6];
void enqueue(int n)
{
    if(front==size)
    {
        printf("\nOverflow\n");
        return;
    }
    else if(front==-1 && rear==-1)
    {
        front=rear=0;
    }
    else
    {
        rear=(rear+1)%size;
    }
    queue[rear]=n;
}

int dequeue()
{
    int data;
    if(front ==-1 && rear==-1)
    {
        printf("UNDERFLOW");
        return -1;
    }
    else if(front==rear)
    {
        data=queue[front];
        front=-1;
        rear=-1;
    }
    else
    {
        data=queue[front];
        front=(front+1)%size;
    }
    return data;
}

void push()
{
    int num;
    printf("Enter the element:");
    scanf("%d",&num);
    enqueue(num);
    int l=1;
    for(int i=front;i!=rear;i=(i+1)%size)
    {
        l++;
    }
    while(l>1)
    {
        int x=dequeue();
        enqueue(x);
        l--;
    }
}

void pop()
{
    int del=dequeue();
    printf("The popped element is : %d",del);
}

void display()
{
    for(int i=front;i!=rear;i=(i+1)%size)
    {
        printf("%d ",queue[i]);
    }
    printf("%d ",queue[rear]);
    printf("\n");
}

int main()
{
    int op;
    int i=1;
    while(i==1)
    {
        printf("\n1:PUSH\n2:POP\n3:Display\n");
        printf("Enter yur choice:");
        scanf("%d",&op);
        switch (op)
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
            default:
            {
                i=0;
                break;
            }
        }
    }
    return 0;
}