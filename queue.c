//QUEUE using array 

#include<stdio.h>
int rear=-1;
int front=-1;
int maxsize=4;
int queue[5];

void traverse()
{
    if(rear==-1 && front==-1)
    {
        printf("There is no element in the queue\n");
        return;
    }
    else
    {
        for(int i=front;i<=rear;i++)
        {
            printf("%d\n",queue[i]);
        }
    }
}

void ENQUEUE()
{
    int val;
    if(rear==maxsize)
    {
        printf("OVERFLOW\n");
        return ;
    }
    printf("Enter the value you want to insert: ");
    scanf("%d",&val);
    if(front==-1 && rear==-1)
    {
        front=rear=0;
        queue[rear]=val;
    }
    else
    {
        rear=rear+1;
        queue[rear]=val;
    }
    // traverse();
}

void DEQUEUE()
{
    int val;
    if(rear==maxsize)
    {
        printf("UNDERFLOW");
        return ;
    }
    if(front==rear)
    {
        val=queue[front];
        front=rear=-1;
    }
    else
    {
        val=queue[front];
        front ++;
    }
    printf("The DEQUEUED Value is : %d\n",val);
    // traverse();
}

void PEEK()
{
    int p;
    if(rear==-1 && front==-1)
    {
        printf("QUEUE is Empty\n");
        return ;
    }
    else
    {
        p=queue[front];
    }
    printf("The peeked value from the QUEUE is : %d\n",p);
}

int main()
{
    ENQUEUE();
    ENQUEUE();
    ENQUEUE();
    traverse();
    DEQUEUE();
    traverse();
    PEEK();
    return 0;
}