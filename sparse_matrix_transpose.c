#include<stdio.h>
#include<stdlib.h>

int sparse(int r,int c,int mat[r][c])
{
    int size=0;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(mat[i][j]!=0)
            {
                size++;
            }
        }
    }
    int **trip[size+1][c];
    int k=0;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(mat[i][j]!=0)
            {
                trip[0][k]=i;
                trip[0][k]=j;
                trip[0][k]=mat[i][j];
            }
        }
    }
    return trip;
}

void printing(int r, int c, int a[r][c])
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            printf("%d",a[i][j]);
        }
        printf("\n");
    }
}

int addelements(int r,int c, int **b[r][c])
{
    printf("Enter the elements:");
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            scanf("%d",&b[i][j]);
        }
    }
    return b;
}

int main()
{
    int r,c;
    printf("Enter the number of rows: ");
    scanf("%d",&r);
    printf("Enter the number of columns: ");
    scanf("%d",&c);
    int arr[r][c];
    addelements(r,c,arr);
    printing(r,c,arr);
    sparse(r,c,arr);
    printing(r,c,arr);
    return 0;
}