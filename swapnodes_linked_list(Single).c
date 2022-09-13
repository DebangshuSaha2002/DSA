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
void swapnodes()
{
    int count=1;
    struct node *ptr1,*ptr2,*ptr,*temp1,*temp2,*temp3;
    ptr=head;

    while(ptr!=NULL)
    {
        if(count==1)
        {
            ptr1=ptr;
            temp1=ptr1->next;
        }
        else if (count == 3)
        {
            ptr2=ptr;
            temp2=ptr2->next;
            temp3=ptr2->next->next;
        }
        ptr=ptr->next;
        count++;
    }
    ptr1->next=temp2;
    temp2->next=ptr2;
    
    ptr2->next=temp1;
    temp1->next=temp3;
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
    swapnodes();
    printf("\nAfter swapping 2nd and 4th node\n");
    linked_list_traversal();

    return 0;
}