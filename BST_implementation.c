//BST Implementation
#include<stdio.h>
#include<stdlib.h>

struct tree 
{
    int data;
    struct tree * lc;
    struct tree * rc;
};
struct tree * root=NULL;

struct tree *create_node(int data)
{
    struct tree *new_node = (struct tree *)malloc(sizeof(struct tree));
    if (new_node == NULL)
    {
        printf("\nMemory for new node can't be allocated");
        return NULL;
    }
    new_node->data = data;
	new_node->lc = NULL;
    new_node->rc = NULL;
    return new_node;
}

void insert(int data)
{
    struct tree *new_node = create_node(data);
    if (new_node != NULL)
    {
        if (root == NULL)
        {
            root = new_node;
            printf("\n* node having data %d was inserted\n", data);
            return;
        }
        struct tree *temp = root;
        struct tree *prev = NULL;
        while (temp != NULL)
        {
            prev = temp;
            if (data > temp->data)
            {
                temp = temp->rc;
            }
            else
            {
                temp = temp->lc;
            }
        }
        // found the last node where the new node should insert
        if (data > prev->data)
        {
            prev->rc = new_node;
        }
        else
        {
            prev->lc = new_node;
        }    
        printf("\n* node having data %d was inserted\n", data);
    }
}

int get_data()
{
    int data;
    printf("\nEnter Data: ");
    scanf("%d", &data);
    return data;
}

int main()
{
    int op=1;
    int data;
    int i=1;
    while(i==1)
    {
        switch (op)
        {
            case 1:
            {
                data=get_data();
                insert(data);
                break;
            }
            default:
            {
                i=0;
                break;
            }
        }
    }
    return 0;
}