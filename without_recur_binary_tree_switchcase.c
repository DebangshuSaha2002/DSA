#include<stdio.h>
#include<stdlib.h>

struct tree
{
    int data;
    struct tree * lc,* rc;
};

void build_tree(struct tree * ptr)
{
    int op;
    struct tree * new;
    printf("Enter the data:");
    scanf("%d",&ptr->data);
    ptr->lc=NULL;
    ptr->rc=NULL;
    printf("Do you want to add left child of %d(1/0) :",ptr->data);
    scanf("%d",&op);
    if(op==1)
    {
        new=(struct tree *)malloc(sizeof(struct tree));
        ptr->lc=new;
        build_tree(new);
    }
    printf("Do you want to add right child of %d(1/0) :",ptr->data);
    scanf("%d",&op);
    if(op==1)
    {
        new=(struct tree *)malloc(sizeof(struct tree));
        ptr->rc=new;
        build_tree(new);
    }
}

struct tree * stack[100];
int top=0;

void push(struct tree * ptr)
{
    if(top==99)
    {
        printf("Stack overflow\n");
        return;
    }
    else
    {
        top=top+1;
        stack[top]=ptr;
    }
}

struct tree * pop(struct tree * ptr)
{
    if(top==-1)
    {
        printf("Underflow\n");
        exit(0);
    }
    else
    {
        ptr=stack[top];
        top=top-1;
    }
    return ptr;
}

void inorder_non_recur(struct tree *root)
{
    struct tree * ptr1;
    stack[top]=NULL;
    ptr1=root;
    while(ptr1!=NULL)
    {
        push(ptr1);
        ptr1=ptr1->lc;
    }
    ptr1=pop(ptr1);
    while(ptr1!=NULL)
    {
        printf("%d ",ptr1->data);
        if(ptr1->rc!=NULL)
        {
            ptr1=ptr1->rc;
            while(ptr1!=NULL)
            {
                push(ptr1);
                ptr1=ptr1->lc;
            }
        }
        ptr1=pop(ptr1);
    }
    printf("\n");
}

void preorder_non_recur(struct tree *root)
{
    struct tree * ptr1;
    stack[top]=NULL;
    ptr1=root;
    while(ptr1!=NULL)
    {
        printf("%d ",ptr1->data);
        if(ptr1->rc!=NULL)
        {
            push(ptr1->rc);
        }
        if(ptr1->lc!=NULL)
        {
            ptr1=ptr1->lc;
        }
        else
        {
            ptr1=pop(ptr1);
        }   
    }
    printf("\n");
}

int main()
{
    struct tree * root;
    root=(struct tree *)malloc(sizeof(struct tree));

    build_tree(root);
    printf("\nIn-order Traversal:\n");
    inorder_non_recur(root);

    printf("\nPre-order Traversal:\n");
    preorder_non_recur(root);
    return 0;
}