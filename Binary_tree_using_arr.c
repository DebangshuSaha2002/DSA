#include<stdio.h>
void build_tree(int t[],int index,int item)
{
    int ch,data;
    t[index]=item;
    printf("Do you want to enter Left Child of %d (1/0): ",item);
    scanf("%d",&ch);
    if(ch==1)
    {
        printf("Enter the Left Child: ");
        scanf("%d",&data);
        build_tree(t,2*index+1,data);
    }
    printf("Do you want to enter Right Child of %d (1/0): ",item);
    scanf("%d",&ch);
    if(ch==1)
    {
        printf("Enter the Right Child: ");
        scanf("%d",&data);
        build_tree(t,2*index+2,data);
    }
}

void inorder(int t[],int index)
{
    int in;
    if(t[index]==-1)
    {
        return;
    }
    inorder(t,(2*index+1)); 
    printf(" %d ",t[index]); 
    inorder(t,(2*index+2)); 
}

void preorder(int t[],int index)
{
    int in;
    if(t[index]==-1)
    {
        return;
    }
    printf(" %d ",t[index]); 
    preorder(t,(2*index+1)); 
    preorder(t,(2*index+2)); 
}

void postorder(int t[],int index)
{
    int in;
    if(t[index]==-1)
    {
        return;
    }
    postorder(t,(2*index+1)); 
    postorder(t,(2*index+2)); 
    printf(" %d ",t[index]); 
}


int main()
{
    int t[20],item;
    for(int i=0;i<20;i++)
    {
        t[i]=-1;
    }
    printf("Enter the Root Node: ");
    scanf("%d",&item);
    build_tree(t,0,item);
    printf("Tree\n");
    printf("\nINORDER TRAVERSAL\n");
    inorder(t,0);
    printf("\nPRE-ORDER TRAVERSAL\n");
    preorder(t,0);
    printf("\nPOST-ORDER TRAVERSAL\n");
    postorder(t,0);
    return 0;
}