//Double Ended Queue 
#include<stdio.h>
int front=-1;
int rear=-1;
int queue[8];
int maxsize=7;


void traversal();
void insert_at_front()
{
    printf("\nInserting at Front:\n");
    int val;
    if(front+1==rear)
    {
        printf("\nOVERFLOW\n");
        return;
    }
    else
    {
        printf("Enter the value:");
        scanf("%d",&val);
        front++;
        queue[front]=val;
    }
    // traversal();
}

void insert_at_rear()
{
    printf("\nInserting at Rear:\n");
    int val;
    if(front+1==rear)
    {
        printf("\nOVERFLOW\n");
        return;
    }
    else if(rear==-1)
    {
        printf("\nEnter the value:");
        scanf("%d",&val);
        rear=maxsize;
        queue[rear]=val;
        rear--;
    }
    else
    {
        printf("\nEnter the value:");
        scanf("%d",&val);
        queue[rear]=val;
        rear--;
    }
}

void delete_from_front()
{
    printf("\nDeleting from front\n");
    int value;
    if(front==-1)
    {
        printf("\nUNDERFLOW\n");
        return;
    }
    else
    {
        value=queue[front];
        front=front-1;
    }
    // traversal();
}

void delete_from_rear()
{
    printf("\nDeleting from rear\n");
    int value;
    if(rear==-1)
    {
        printf("\nUNDERFLOW\n");
        return;
    }
    else
    {
        value=queue[rear];
        rear=rear+1;
    }
    // traversal();
}

void traversal()
{
    if(front==-1 && rear==-1)
    {
        printf("\nQueue is Empty\n");
        return;
    }
    else
    {
        printf("\nThe elements in the queue is:\n");
        for(int i=0;i<=maxsize;i++)
        {
            if(queue[i]!=0)
            {
                printf("%d\n",queue[i]);
            }
        }
    }
}

int main()
{
    for(int i=0;i<=maxsize;i++)
    {
        queue[i]=0;
    }
    insert_at_front();
    traversal();
    insert_at_front();
    traversal();
    insert_at_rear();
    traversal();
    insert_at_rear();
    traversal();
    delete_from_front();
    traversal();
    insert_at_rear();
    traversal();
    delete_from_rear();
    traversal();
    return 0;
}