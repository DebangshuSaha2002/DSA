
#include<stdio.h>
int top1=-1;
int top2=-1;
int stack1[10];
int stack2[10];
int c=0;
void push1(int x)
{
    if(top1==9)
    {
        printf("OVERFLOW\n");
        return;
    }
    else
    {
        top1=top1+1;
        stack1[top1]=x;
    }
}

int pop1()
{
    int data1=stack1[top1];
    top1--;
    return data1;
}

void push2(int x)
{
    if(top2==9)
    {
        printf("OVERFLOW\n");
        return;
    }
    else
    {
        top2=top2+1;
        stack2[top2]=x;
    }
}

int pop2()
{
    int data2=stack2[top2];
    top2--;
    return data2;
}

void enqueue()
{
    int n;
    printf("Enter the data:");
    scanf("%d",&n);
    push1(n);
    c++;
}

void dequeue()
{
    for(int i=0;i<=c;i++)
    {
        push2(pop1());
    }
    pop2();
    c--;
    for(int i=0;i<=c;i++)
    {
        push1(pop2());
    }

}

void display()
{
    for(int i=0;i<=top1;i++)
    {
        printf("%d ",stack1[i]);
    }
}
int main()
{
    int op;
    int i=1;
    while(i==1)
    {
        printf("\n1:ENQUEUE\n2:DEQUEUE\n3:Display\n");
        printf("Enter yur choice:");
        scanf("%d",&op);
        switch (op)
        {
            case 1:
            {
                enqueue();
                break;
            }
            case 2:
            {
                dequeue();
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