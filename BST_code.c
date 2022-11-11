#include<stdio.h>
#include<stdlib.h>

struct tree
{
    int data;
    struct tree * lc,* rc;
};

void insert(struct tree * root)
{
    int n;
    printf("Enter the data:");
    scanf("%d",&n);
    struct tree * new=(struct tree *)malloc(sizeof(struct tree));
    new->data=n;
    new->lc=NULL;
    new->rc=NULL;

    if(new!=NULL)
    {
        if(root==NULL)
        {
            root=new;
            printf("\nNode with %d value was inserted\n",n);
        }
        else
        {
            struct tree * temp=root;
            struct tree * prev=NULL;
            while(temp!=NULL)
            {
                prev=temp;
                if(n>temp->data)
                {
                    temp=temp->rc;
                }
                else
                {
                    temp=temp->lc;
                }
            }
            if(n>prev->data)
            {
                prev->rc=new;
            }
            else
            {
                prev->lc=new;
            }
            printf("\nNode with %d value was inserted\n",n);
        }
    }
}

struct tree * smallest(struct tree * root)
{
    struct tree * ptr;
    ptr=root;
    while(ptr!=NULL && ptr->lc!=NULL)
    {
        ptr=ptr->lc;
    }
    return ptr;
}

struct tree * largest(struct tree * root)
{
    struct tree * ptr;
    ptr=root;
    while(ptr!=NULL && ptr->rc!=NULL)
    {
        ptr=ptr->rc;
    }
    return ptr;
}

void inorder(struct tree * r)
{
    if(r==NULL)
    {
        return;
    }
    else
    {
        inorder(r->lc);
        printf("%d ",r->data);
        inorder(r->rc);
    }
}

int search(struct tree * root,int num)
{
    struct tree * temp=root;
    while(temp!=NULL)
    {
        if(num==temp->data)
        {
            return 1;
        }
        else if(num>temp->data)
        {
            temp=temp->rc;
        }
        else
        {
            temp=temp->lc;
        }
    }
    return 0;
}

struct tree * left_max(struct tree * root)
{
    root=root->lc;
    while(root->rc!=NULL)
    {
        root=root->rc;
    }
    return root;
}
struct tree * delete(struct tree * root,int val)
{
    struct tree * ptr;
    if(root==NULL)
    {
        return NULL;
    }

    if(root->lc == NULL && root->rc==NULL)
    {
        free(root);
        return NULL;
    }

    if(val>root->data)
    {
        root->rc=delete(root->rc,val);
    }
    else if(val<root->data)
    {
        root->lc=delete(root->lc,val);
    }
    else
    {
        ptr=left_max(root);
        root->data=ptr->data;
        root->lc=delete(root->lc,ptr->data);
    }
    return root;
}
int main()
{
    int n,num;
    struct tree * root=NULL;
    struct tree * small=NULL;
    struct tree * large=NULL;
    root=(struct tree *)malloc(sizeof(struct tree));
    char ch;
    printf("Do you want to enter a new node to BST(y/n)? :");
    scanf("%s",&ch);
    while(ch=='y')
    {
        insert(root);
        printf("Do you want to enter a new node to BST(y/n)? :");
        scanf("%s",&ch);
    }
    inorder(root);
    small=smallest(root);
    printf("\nThe samllest node data is : %d",small->data);
    large=largest(root);
    printf("\nThe samllest node data is : %d",large->data);
    printf("\nEnter the element to search:");
    scanf("%d",&n);
    if(search(root,n)==1)
    {
        printf("\nElement is present in the tree");
    }
    else
    {
        printf("\nElement is not present in the tree");
    }
    printf("Enter the value to delete:");
    scanf("%d",&num);
    delete(root,num);
    inorder(root);
    return 0;
}