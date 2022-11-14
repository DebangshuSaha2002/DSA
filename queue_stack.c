#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * next;
};
struct node * stack1=NULL;
struct node * stack2=NULL;
void push(struct node ** stack,int item)
{
    struct node * new;
    new=(struct node *)malloc(sizeof(struct node));
    new->data=item;
    new->next=*stack;
    *stack=new;
}

int pop(struct node ** stack)
{
    int del;
    if(*stack==NULL)
    {
        printf("Underflow\n");
        return -1;
    }
    else
    {
        del=(*stack)->data;
        *stack=(*stack)->next;
    }
    return del;
}

void display(struct node **stack)
{
    if(*stack==NULL)
    {
        printf("Empty Stack\n");
        return;
    }
    else
    {
        struct node * ptr=*stack;
        while(ptr!=NULL)
        {
            printf("%d ",ptr->data);
            ptr=ptr->next;
        }
    }
}

void enqueue(struct node ** stack,struct node ** stackA,int item)
{
    while(*stack!=NULL)
    {
        int x=pop(stack);
        push(stackA,x);
    }
    push(stack,item);
    while(*stackA!=NULL)
    {
        int y=pop(stackA);
        push(stack,y);
    }
}

void dequeue(struct node **stack)
{   
    int x=pop(stack);
    printf("Deleted element is %d\n",x);
}

int main(){
    int op=1;
    while(op==1||op==2||op==3){
        printf("Enter 1 to add an element\nEnter 2 to pop an element\nEnter 3 to display stack\nEnter any other number to exit: ");
        scanf("%d",&op);
        if(op==1){
            int n;
            printf("Enter data: ");
            scanf("%d",&n);
            enqueue(&stack1,&stack2,n);
        }
        else if(op==2){
            dequeue(&stack1);
        }
        else if(op==3){
            display(&stack1);
        }
        else{
            break;
        }
    }
}

