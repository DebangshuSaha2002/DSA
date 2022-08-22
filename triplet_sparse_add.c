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

int sparse_to_triplet(int r,int c,int a[r][c])
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
    return size;
}

void triplet(int r,int c,int a[r][c],int b[r][c])
{
    int s1=sparse_to_triplet(r,c,a);
    int s2=sparse_to_triplet(r,c,b);
    int triplet1[s1][3];
    int triplet2[s2][3];
    int k=0;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(a[i][j]!=0)
            {
                triplet1[k][0]=i;
                triplet1[k][1]=j;
                triplet1[k][2]=a[i][j];
                k++;
            }
        }
    }
    printf("\nPrinting the triplet form of sparse matrix A:\n");
    printing_sparse(s1,triplet1);
    int l=0;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(a[i][j]!=0)
            {
                triplet2[l][0]=i;
                triplet2[l][1]=j;
                triplet2[l][2]=a[i][j];
                l++;
            }
        }
    }
    printf("\nPrinting the triplet form of sparse matrix B:\n");
    printing_sparse(s1,triplet2);

    int add[s1+s2][3];
    int m=0;
	int f;
	for(int i=1;i<=s1;i++)
	{
		f=0;
		for(int j=1;j<=s2;j++)
		{
			if((triplet1[i][0] == triplet2[j][0]) && (triplet1[i][1] == triplet2[j][1]))
			{
				f=1;
				break;
			}
		}
		if(f==1)
		{
			add[m][0] = triplet1[i][0];
			add[m][1] = triplet1[i][1];
			add[m][2] = triplet1[i][2] + triplet2[i][2];
			m++;
		}
		else
		{
			add[m][0] = triplet1[i][0];
			add[m][1] = triplet1[i][1];
			add[m][2] = triplet1[i][2];
			m++;
		}
	}
	for(int i=1;i<=s2;i++)
	{
		f=0;
		for(int j=1;j<=s1;j++)
		{
			if((triplet2[i][0] == triplet1[j][0]) && (triplet2[i][1] == triplet1[j][1]))
			{
				f=1;
				break;
			}
		}
		if(f==0)
		{
			add[m][0] = triplet2[i][0];
			add[m][1] = triplet2[i][1];
			add[m][2] = triplet2[i][2];
			m++;
		}
	}
	printf("\n\nTriplet Representation of Sum\n\n");
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<3;j++)
        {
			printf("%d  ", add[i][j]);
        }
		printf("\n");
	}
}
void printing_sparse(int s,int trip[][3])
{
    printf("\nPrinting the triplet form of sparse matrix:\n");
    for(int i=0;i<s;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("%d\t",trip[i][j]);
        }
        printf("\n");
    }
}

void add_triplets(int r,int c,int a[],int b[])
{
    int A=sparse_to_triplet(r,c,a);
    int B=sparse_to_triplet(r,c,b);
    int add[A+B][3];
    for(int i=0;i<=A;i++)
    {
        for(int j=0;j<=B;j++)
        {

        }
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
    int b[r][c];
    printf("\nFor Matrix A: \n");
    input_to_matrix(r,c,a);
    printf("\nFor Matrix B: \n");
    input_to_matrix(r,c,b);

    printf("The Original Sparse Matrix A: \n");
    printing(r,c,a);
    printf("\nThe Original Sparse Matrix B: \n");
    printing(r,c,b);

    printf("\nThe triplet form of Sparse Matrix A: \n");
    triplet(r,c,a,b);
    printf("\nThe triplet form of Sparse Matrix B: \n");
    triplet(r,c,a,b);
}