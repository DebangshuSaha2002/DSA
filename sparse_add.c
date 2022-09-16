#include<stdio.h>
#include<stdlib.h>

int ** create(int row,int col,int nz)
{
    int **M;
    M=(int **)malloc((nz+1)*sizeof(int **));
    for(int i=0;i<=nz;i++)
    {
        M[i]=(int *)malloc(3*sizeof(int));
    }
    return M;
}

void display(int **M)
{
    int t=M[0][2];
    printf("Sparse Matrix in triplet format is:\n");
    for(int i=0;i<t;i++)
    {
        printf("%d\t%d\t%d\n",M[i][0],M[i][1],M[i][2]);
    }
}

int ** sparseAdd(int **M1, int **M2)
{
    int r1=M1[0][0];
    int r2=M2[0][0];
    int c1=M1[0][1];
    int c2=M2[0][1];
    int t1=M1[0][2];
    int t2=M2[0][2];
    
    int i,j,k;
    i=j=k=1;
    int t3=t1+t2+1;
    
    int **M3;
    M3=(int **)malloc((t3+1)*sizeof(int **));
    for(int i=0;i<=t3;i++)
    {
        M3[i]=(int *)malloc(3*sizeof(int));
    }
    
    M3[0][0]=r1;
    M3[0][1]=c1;
    
    while(i<=t1 && j<=t2)
    {
        if(M1[i][0]==M2[j][0] && M1[i][1]==M2[j][1])
        {
            M3[k][0]=M1[i][0];
            M3[k][1]=M1[i][1];
            M3[k][2]=M1[i][2]+M2[j][2];
            i++;
            j++;
            k++;
        }
        else if(M1[i][0]==M2[j][0] && M1[i][1]<M2[j][1])
        {
            M3[k][0]=M1[i][0];
            M3[k][1]=M1[i][1];
            M3[k][2]=M1[i][2];
            i++;
            k++;
        }
        else if(M1[i][0]==M2[j][0] && M1[i][1]>M2[j][1])
        {
            M3[k][0]=M2[j][0];
            M3[k][1]=M2[j][1];
            M3[k][2]=M2[j][2];
            j++;
            k++;
        }
        else if(M1[i][0]<M2[j][0])
        {
            M3[k][0]=M1[i][0];
            M3[k][1]=M1[i][1];
            M3[k][2]=M1[i][2];
            i++;
            k++;
        }
        else
        {
            M3[k][0]=M2[j][0];
            M3[k][1]=M2[j][1];
            M3[k][2]=M2[j][2];
            j++;
            k++;
        }
    }
    if(i<=t1)
    {
        for(int q=i;q<=t1;q++)
        {
            M3[k][0]=M1[q][0];
            M3[k][1]=M1[q][1];
            M3[k][2]=M1[q][2];
            k++;
        }
    }
    else
    {
        for(int q=j;q<=t2;q++)
        {
            M3[k][0]=M2[q][0];
            M3[k][1]=M2[q][1];
            M3[k][2]=M2[q][2];
            k++;
        }
    }
    M3[0][2]=k;
    return M3;
}

int main()
{
    int r1,r2,c1,c2,t1,t2 ;
    int i,j;
    printf("Enter the Size of 1st Matrix:");
    scanf("%d%d",&r1,&c1);
    printf("Enter the number of non-zero elements present in the Matrix: ");
    scanf("%d",&t1);
    int **M1;

    M1=create(r1,c1,t1);
    printf("Enter the Size of 2st Matrix:");
    scanf("%d%d",&r2,&c2);
    printf("Enter the number of non-zero elements present in the Matrix: ");
    scanf("%d",&t2);
    int **M2;
    M2=create(r2,c2,t2);
    
    printf("Enter the Sparse Matrix 1 in triplet format:\n");
    for(i=1;i<=t1;i++)
    {
        scanf("%d%d%d",&M1[i][0],&M1[i][1],&M1[i][2]);
    }
    printf("Enter the Sparse Matrix 2 in triplet format:\n");
    for(j=1;j<=t2;j++)
    {
        scanf("%d%d%d",&M2[j][0],&M2[j][1],&M2[j][2]);
    }
    M1[0][0]=r1;
    M1[0][1]=c1;
    M1[0][2]=t1;
    M2[0][0]=r2;
    M2[0][1]=c2;
    M2[0][2]=t2;
    int **M3=sparseAdd(M1,M2);
    display(M3);
    
}