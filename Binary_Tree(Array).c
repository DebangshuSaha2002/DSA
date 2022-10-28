//Binary Tree using Array

#include<stdio.h>
int main()
{
    int level;
    char ch;
    printf("Enter the number of levels in the tree:");
    scanf("%d",&level);
    int nodes=((2^(level+1))-1);
    int tree[10];
    int i=1;
    printf("Enter the value for the root node:");
    scanf("%d",&tree[i]);
    printf("L for Left subtree and R for Right subtree\n");
    scanf(" %s",&ch);
    while(i)
    {
        while(ch=='L')
        {
            printf("Enter the value for the left node:");
            scanf("%d",&tree[(2*i)+1]);
            i++;
            printf("L for Left subtree and R for Right subtree\n");
            scanf(" %s",&ch);
        }
        while(ch=='R')
        {
            printf("Enter the value for the Right node:");
            scanf("%d",&tree[(2*i)+2]);
            i++;
            printf("L for Left subtree and R for Right subtree\n");
            scanf(" %s",&ch);
        }
    }

    for(int i=0;i<nodes;i++)
    {
        printf("%d\n",tree[i]);
    }
    return 0; 
}