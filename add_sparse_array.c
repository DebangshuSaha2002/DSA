#include<stdio.h>
#include<stdlib.h>

void inputmatrix(int m,int n,int arr[m][n])
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("\nMatrix [%d][%d]: ");
            scanf("%d",&arr[i][j]);
        }
    }
}

int main()
{
    int row;
    int col;
    printf("\nEnter the number of rows: ");
    scanf("%d",&row);
    printf("\nEnter the number of columns: ");
    scanf("%d",&col);
    int matt1[row][col];
    printf("\nMATRIX 1:\n");
    inputmatrix(row,col,matt1);

    int matt2[row][col];
    printf("\nMATRIX 1:\n");
    inputmatrix(row,col,matt2);
    return 0;
}