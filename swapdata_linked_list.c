#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node *next;
}*head=NULL;

void linked_list_traversal()
{
    struct node * ptr;
    ptr=head;
    while(ptr!=0)
    {
        printf("Element: %d\n",ptr->data);
        ptr=ptr->next;
    }
}
void swapdata()
{
    int count=1;
    struct node *ptr1,*ptr2,*ptr,*temp;
    ptr=head;

    while(ptr!=NULL)
    {
        if(count==2)
        {
            ptr1=ptr;
        }
        else if (count == 5)
        {
            ptr2=ptr;
        }
        ptr=ptr->next;
        count++;
    }
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=ptr1->data;
    ptr1->data=ptr2->data;
    ptr2->data=temp->data;
}
void adding_to_ll(struct node *ptr, struct node *new)
{
    char ch;
    printf("Do you want to add more? (Y/N): ");
    scanf("%s", &ch);
    while(ch=='y')
    {
        new=(struct node *)malloc(sizeof(struct node));
        printf("Enter the value: ");
        scanf("%d",&new->data);
        new->next=NULL;
        ptr->next=new;
        ptr=new;
        printf("Do you want to add more? (Y/N): ");
        scanf(" %c",&ch);
    }
}

int main()
{
    struct node *ptr,*new;

    int val;
    new=(struct node *)malloc(sizeof(struct node));
    printf("Enter the value: ");
    scanf("%d",&new->data);
    new->next=NULL;
    head=new;
    ptr=head;

    adding_to_ll(ptr,new);
    linked_list_traversal();
    swapdata();
    printf("\nAfter swapping 2nd and 5th data\n");
    linked_list_traversal();

    return 0;
}