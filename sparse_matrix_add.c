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
void addsparse(int b1[MAX][3],int b2[MAX][3],int b3[MAX][3])
{
   
int t1,t2,i,j,k;
   
if(b1[0][0]!=b2[0][0]||b1[0][1]!=b2[0][1])
    {
       
printf("nYou have entered invalid matrix!!Size must be equal");
       
exit(0);
    }
   
t1=b1[0][2];
   
t2=b2[0][2];
   
i=j=k=0;
   
b3[0][0]=b1[0][0];
   
b3[0][1]=b1[0][1];
   
while(i<=t1&&j<=t2)
    {
       
if(b1[i][0]<b2[j][0])      
//row numbers are not equal
       
{
           
b3[k][0]=b1[i][0];
           
b3[k][1]=b1[i][1];
           
b3[k][2]=b1[i][2];
           
k++;
           
i++;
       
}
       
else if(b2[j][0]<b1[i][0])      
//row numbers are not equal
       
{
           
b3[k][0]=b2[j][0];
           
b3[k][1]=b2[j][1];
           
b3[k][2]=b2[j][2];
       
    k++;
           
j++;
       
}
       
else if(b1[i][1]<b2[j][1])      
//row numbers are equal, compare column
       
{
           
b3[k][0]=b1[i][0];
           
b3[k][1]=b1[i][1];
           
b3[k][2]=b1[i][2];
           
k++;
           
i++;
        }
       
else if(b2[j][1]<b1[i][1])      
//row numbers are equal, compare column

       
{
           
b3[k][0]=b2[j][0];
           
b3[k][1]=b2[j][1];
           
b3[k][2]=b2[j][2];
           
k++;
           
j++;
       
}
       
else
       
{
           
b3[k][0]=b1[i][0];      //row and
column numbers are equal
           
b3[k][1]=b1[i][1];
           
b3[k][2]=b1[i][2]+b2[j][2];
           
k++;
           
i++;
           
j++;
       
}
    }
   
while(i<=t1)        //copy
remaining terms from b1
    {
       
b3[k][0]=b1[i][0];
       
b3[k][1]=b1[i][1];
       
b3[k][2]=b1[i][2];
       
i++;
       
k++;
    }
   
while(j<=t2)        //copy
remaining terms from b2
    {
       
b3[k][0]=b2[j][0];
       
b3[k][1]=b1[j][1];
       
b3[k][2]=b1[j][2];
       
j++;
       
k++;
    }
   
b3[0][2]=k-1;       //set number
of terms in b3
}

void display(int **M)
{
    // int r=M1[0][0];
    // int c=M1[0][1];
    int t=M[0][2];
    printf("Sparse Matrix in triplet format is:\n");
    for(int i=0;i<t;i++)
    {
        printf("%d\t%d\t%d\n",M[i][0],M[i][1],M[i][2]);
    }
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
    // printf("%d",M3[0][2]);
    display(M3);
    
}



