//Traversal using recursion

#include<stdio.h>
#include<stdlib.h>
struct tree
{
    int data;
    struct tree *lc,*rc;
};

void buildtree(struct tree *ptr)
{
    int op;
    struct tree * new;
    printf("Enter the data: ");
    scanf("%d",&ptr->data);
    ptr->lc=NULL;
    ptr->rc=NULL;
    printf("Do you want to add left child of %d(1/0):",ptr->data);
    scanf("%d",&op);
    if(op==1)
    {
        new=(struct tree *)malloc(sizeof(struct tree));
        ptr->lc=new;
        buildtree(new);
    }
    printf("Do you want to add right child of %d(1/0):",ptr->data);
    scanf("%d",&op);
    if(op==1)
    {
        new=(struct tree *)malloc(sizeof(struct tree));
        ptr->rc=new;
        buildtree(new);
    }
}

void Inorder_Traversal(struct tree* n) 
{
    if (n==NULL)
    {
        return;
    }
    Inorder_Traversal(n->lc);
    printf("%d ",n->data);
    Inorder_Traversal(n->rc);
}

void Preorder_traversal(struct tree *n)
{
    if(n==NULL)
    {
        return;
    }
    printf("%d ",n->data);
    Preorder_traversal(n->lc);
    Preorder_traversal(n->rc);
}

void Postorder_Traversal(struct tree * n)
{
    if(n==NULL)
    {
        return;
    }
    Postorder_Traversal(n->lc);
    Postorder_Traversal(n->rc);
    printf("%d ",n->data);
}

int main()
{
    struct tree *root;
    root=(struct tree *)malloc(sizeof(struct tree));
    buildtree(root);

    printf("\nINORDER TRAVERSAL\n");
    Inorder_Traversal(root);

    printf("\nPRE-ORDER TRAVERSAL\n");
    Preorder_traversal(root);

    printf("\nPOST-ORDER TRAVERSAL\n");
    Postorder_Traversal(root);

    return 0;
}