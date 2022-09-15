#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
}*head=NULL;

void linkedListTraversal(struct node *ptr);
void insert_first();
void insert_last();
void insert_pos(int pos);
void del_first();
void del_last();
void del_pos(int pos);

void insert_first()
{
    printf("Inserting element at the first: \n");
    struct node *new;
    new=(struct node *)malloc(sizeof(struct node));
    printf("Enter the value: ");
    scanf("%d",&new->data);
    new->next=head;
    head=new;
    linkedListTraversal(head);
}

void insert_last()
{
    printf("Inserting element at the last: \n");
    struct node *new;
    new=(struct node *)malloc(sizeof(struct node));
    struct node *ptr;

    printf("Enter a value: ");
    scanf("%d",&new->data);
    ptr=head;
    while (ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=new;
    linkedListTraversal(head);
}

void insert_pos(int pos)
{
    printf("Inserting at a position: \n");
    struct node *new;
    new=(struct node *)malloc(sizeof(struct node));
    struct node *ptr;

    printf("Enter a value: ");
    scanf("%d",&new->data);
    ptr=head;
    int count=1;
    while (ptr!=NULL && count!=pos-1)
    {
        ptr=ptr->next;
        count+=1;
    }
    new->next=ptr->next;
    ptr->next=new;
    linkedListTraversal(head);
}

void del_first()
{
    printf("Deleting the first element: \n");
    struct node *ptr;
    ptr=head;
    if(head==NULL)
    {
        printf("Deletion not possible ");
        exit(0);
    }
    head=head->next;
    free(ptr);
    printf("\n");
    linkedListTraversal(head);
}

void del_last()
{
    struct node * ptr;
    struct node * temp;
    ptr=head;

    while((ptr->next)->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=NULL;
    linkedListTraversal(head);
}

void del_pos(int pos)
{
    int count=1;
    struct node *temp;
    struct node *ptr;
    ptr=head;
    while(ptr!=NULL && count!=pos-1)
    {
        ptr=ptr->next;
        count++;
    }
    // ptr->next=temp->next;
    temp=ptr->next;
    ptr->next=temp->next;
    linkedListTraversal(head);
    free(temp);
}


void linkedListTraversal(struct node* ptr)
{
    while(ptr!=NULL)
    {
        printf("Element: %d \n", ptr->data);
        ptr=ptr->next;
    }
}


void adding_tothe_ll(struct node *ptr, struct node *new)
{
    char ch;
    printf("Do you want to add (y,n) \n");
    scanf(" %c",&ch);
    while(ch=='y')
    {
        new=(struct node *)malloc(sizeof(struct node));
        printf("Enter the new value: \n");
        scanf("%d",&new->data);
        new->next=NULL;
        ptr->next=new;
        ptr=new;
        printf("Do you want to add more values? (y,n) \n");
        scanf(" %c",&ch);
    }
}

int main()
{
    //struct node *head;
    struct node *new;
    struct node *ptr;
    //head=NULL;

    new=(struct node *)malloc(sizeof(struct node));
    printf("Enter the value: \n");
    scanf("%d",&new->data);
    new->next=NULL;
    head=new;
    ptr=head;
    int num;
    printf("\n1:Add numbers to the linked list\n2:Insert element at first\n3:Insert element at last\n4.Insert element at a position\n");
    printf("5.Delete element at the first\n6.Delete element at the last\n7.Delete element at a position\n");
    int i=0;
    while(i!=1){
    printf("Enter your choice: ");
    scanf("%d",&num);

    switch (num)
    {
        case 1:
        {
            adding_tothe_ll(ptr,new);
            linkedListTraversal(ptr);
            printf("\n");
            break;
        }
        case 2:
        {
            insert_first();
            printf("\n");
            break;
        }
        case 3:
        {
            insert_last();
            printf("\n");
            break;
        }
        case 4:
        {
            int n1;
            printf("Enter the position where u want to add the element: ");
            scanf("%d",&n1);
            insert_pos(n1);
            printf("\n");
            break;
        }
        case 5:
        {
            del_first();
            printf("\n");
            break;
        }
        case 6:
        {
            del_last();
            printf("\n");
            break;
        }
        case 7:
        {
            int n2;
            printf("Enter the position whose value u want to delete: ");
            scanf("%d",&n2);
            del_pos(n2);
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

