#include<stdio.h>

void input_to_matrix(int r,int c,int a[r][c])
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            printf("a[%d][%d]\n",i,j);
            scanf("%d",&a[i][j]);
        }
    }
}

void printing(int r,int c,int a[r][c])
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
}

int check_ifsparse(int r,int c,int a[r][c])
{
    int count=0;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(a[i][j]==0)
            {
                count+=1;
            }
        }
    }
    if(count>=((r*c)/2))
    {
        count=1;
    }
    else{
        count=0;
    }
    return count;
}

int main()
{
    int r,c;
    printf("Enter the number fo rows: ");
    scanf("%d",&r);
    printf("\nEnter the number of columns: ");
    scanf("%d",&c);
    int a[r][c];
    input_to_matrix(r,c,a);
    printing(r,c,a);
    if(check_ifsparse(r,c,a)==1)
    {
        printf("Yes, its a sparse matrix");
    }
    else if(check_ifsparse(r,c,a)==0)
    {
        printf("Sorry, its not a sparse matrix");
    }
}