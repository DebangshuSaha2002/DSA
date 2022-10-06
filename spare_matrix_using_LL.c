#include<stdio.h>
#include<stdlib.h>

struct node
{
    int r_pos;
    int c_pos;
    int val;
    struct node * next;
}*head=NULL;

void printing();

void create(int value,int row,int col)
{
    struct node * temp,*temp1;
    temp=head;
    if(head==NULL)
    {
        temp=(struct node *)malloc(sizeof(struct node));
        temp->r_pos=row;
        temp->c_pos=col;
        temp->val=value;
        temp->next=NULL;
        head=temp;
    }
    else
    {
        temp1=head;
        while(temp1->next!=NULL)
        {
            temp1=temp1->next;
        }
        temp=(struct node *)malloc(sizeof(struct node));
        temp->r_pos=row;
        temp->c_pos=col;
        temp->val=value;
        temp1->next=temp;
        temp->next=NULL;
    }
    // printing();
}

void printing()
{
    struct node * p;
    p=head;
    printf("ROW\tCOL\tVAL\n");
    while(p!=NULL)
    {
        printf("%d\t%d\t%d\n",p->r_pos,p->c_pos,p->val);
        p=p->next;
    }
}

int main()
{
    int r,c;
    printf("Enter the number of rows: ");
    scanf("%d",&r);
    printf("Enter the number of columns: ");
    scanf("%d",&c);
    int arr[r][c];
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }

    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(arr[i][j]!=0)
            {
                create(arr[i][j],i,j);
            }
        }
    }
    printing();
    return 0;
}