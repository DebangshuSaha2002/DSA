//Debangshu Saha (21052581)
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
    for(int i=0;i<20;i++)
    {
        if(t[i]==-1)
        {
            printf(" - ");
        }
        else
        {
            printf("%d ",t[i]);
        }
    }
}