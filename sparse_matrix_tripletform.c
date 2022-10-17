#include<stdio.h>

void input_to_matrix(int r,int c,int a[r][c])
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            printf("a[%d][%d]: ",i,j);
            scanf("%d",&a[i][j]);
            printf("\n");
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

void sparse_to_triplet(int r,int c,int a[r][c])
{
    int size=0;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(a[i][j]!=0)
            {
                size++;
            }
        }
    }
    int triplet[size][3];
    int k=0;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(a[i][j]!=0)
            {
                triplet[k][0]=i;
                triplet[k][1]=j;
                triplet[k][2]=a[i][j];
                k++;
            }
        }
    }

    printf("\nPrinting the triplet form of sparse matrix:\n");
    printf("\nRow\tColumn\tValue\n");
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("%d\t",triplet[i][j]);
        }
        printf("\n");
    }
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
    sparse_to_triplet(r,c,a);
}