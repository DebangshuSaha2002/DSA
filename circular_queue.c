//Circular Queue

#include<stdio.h>
int front=-1;
int rear=-1;
int size=8;

int queue[8];

void enqueue()
{
    int val;
    if((front==0 && rear==size-1) || (front==rear+1))
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
    printf("Enter the value: ");
    scanf("%d",&val);
    queue[rear]=val;
}

void dequeue()
{
    int value;
    if(front==-1 && rear==-1)
    {
        printf("\nUNDERFLOW\n");
        return;
    }
    else if(front==0 && rear==0)
    {
        value=queue[front];
        front=rear=-1;
    }
    else
    {
        value=queue[front];
        front=(front+1)%size;
    }
    printf("DEQUEUED Value: %d\n",value);
}

void traversing()
{
    if(front==-1 && rear==-1)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("\nElements in the queue is:\n");
        for(int i=front;i!=rear;i++)
        {
            printf("%d\n",queue[i]);
        }
        printf("%d\n",queue[rear]);
    }
}

int main()
{
    char ch;
    printf("Do you want to enqueue (y/n): ");
    scanf(" %c",&ch);
    while(ch=='y')
    {
        enqueue();
        printf("Do you want to enqueue (y/n): ");
        scanf(" %c",&ch);
    }
    traversing();

    printf("After Dequeue the queue is: \n");
    dequeue();
    traversing();
    return 0;
}
