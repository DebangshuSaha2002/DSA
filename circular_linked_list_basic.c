#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * next;
}*head=NULL;

void LL_traversal()
{
    struct node *ptr;
    ptr=head;
    do
    {
        printf("Element: %d\n",ptr->data);
        ptr=ptr->next;
    }while(ptr!=head);
}

void insert_first()
{
    printf("INSERTING AT FIRST: \n");
    struct node * new;
    char ch;
    int value;
    printf("Do you want to continue (y/n)? ");
    scanf(" %s",&ch);
    while(ch=='y')
    {
        new=(struct node *)malloc(sizeof(struct node));
        printf("Enter the number: ");
        scanf("%d",&value);
        new->data=value;
        if(head==NULL)
        {
            head=new;
            new->next=head;
        }
        else
        {
            struct node * ptr=head;
            while(ptr->next!=head)
            {
                ptr=ptr->next;
            }
            ptr->next=new;
            new->next=head;
            head=new;
        }
        printf("Do you want to continue (y/n)? ");
        scanf(" %s",&ch); 
    }
    LL_traversal();
}

void insert_last()
{
    printf("INSERTING AT LAST: \n");
    struct node * new;
    char ch;
    int value;
    printf("Do you want to continue (y/n)? ");
    scanf(" %s",&ch);
    while(ch=='y')
    {
        new=(struct node *)malloc(sizeof(struct node));
        printf("Enter the number: ");
        scanf("%d",&value);
        new->data=value;
        if(head==NULL)
        {
            new->next=head;
            head=new;
        }
        else
        {
            struct node * ptr=head;
            while(ptr->next!=head)
            {
                ptr=ptr->next;
            }
            ptr->next=new;
            new->next=head;
        }
        printf("Do you want to continue (y/n)? ");
        scanf(" %s",&ch);
    }
    LL_traversal();
}

void insert_pos()
{
    struct node * new;
    int pos,value,count=1;
    new=(struct node *)malloc(sizeof(struct node));
    printf("Enter the position where you want to insert: ");
    scanf("%d",&pos);
    printf("Enter the number: ");
    scanf("%d",&value);
    new->data=value;
    struct node * p=head;
    do
    {
        p=p->next;
        count++;
    } while (p!=head && count!=pos-1);
    new->next=p->next;
    p->next=new;
    LL_traversal();
}

void del_first()
{
    printf("Deleting first element:\n");
    struct node * ptr,*p;

    if(head==NULL)
    {
        printf("Deletion not possible\n");
        exit(0);
    }
    else
    {
        // ptr=head;
        p=head;
        while(p->next!=head)
        {
            p=p->next;
        }
        p->next=head->next;
        free(head);
        head=p->next;
    }
    LL_traversal();
}

void del_last()
{
    printf("Deleting last element:\n");
    struct node * ptr,* temp;
    ptr=head;
    while(ptr->next->next!=head)
    {
        ptr=ptr->next;
    }
    temp=ptr->next;
    ptr->next=head;
    free(temp);
    LL_traversal();
}

void del_pos()
{
    struct node * ptr,* temp;
    int pos,count=1;
    printf("Enter the position whose value u want to delete: ");
    scanf("%d",&pos);
    ptr=head;
    do
    {
        ptr=ptr->next;
        count++;
    }while(ptr!=head && count!=pos-1);

    temp=ptr->next;
    ptr->next=temp->next;
    free(temp);
    LL_traversal();
}

int main()
{
    int choice;
    printf("\nCIRCULAR LINKED LIST OPERATIONS:\n");
    printf("\n1:Insert at first\n2:Insert at last\n3:Insert at pos\n4:Delete at first\n5:Delete at last\n6:Delete at position\n");
    int i=0;
    while(i!=1)
    {
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch (choice)
        {
            case 1:
            {
                insert_first();
                printf("\n");
                break;
            }
            case 2:
            {
                insert_last();
                printf("\n");
                break;
            }
            case 3:
            {
                insert_pos();
                printf("\n");
                break;
            }
            case 4:
            {
                del_first();
                printf("\n");
                break;
            }
            case 5:
            {
                del_last();
                printf("\n");
                break;
            }
            case 6:
            {
                del_pos();
                printf("\n");
                break;
            }
            default:
            {
                i=1;
            }
        }
    }
    return 0;
}
