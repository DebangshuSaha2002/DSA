#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node *prev;
    int data;
    struct node *next;
}*head=NULL;

int main(){
    struct node *ptr,*new;
    new=(struct node *)malloc(sizeof(struct node));
    // head=new;
    printf("Enter the value: ");
    scanf("%d",&new->data);
    new->prev=head;
    new->next=NULL;
    head=new;
    ptr=head;
    char ch;
    printf("Do you want to add (y,n) \n");
    scanf(" %c",&ch);
    while(ch=='y'){
        new=(struct node *)malloc(sizeof(struct node));
        printf("Enter the new value: \n");
        scanf("%d",&new->data);
        new->next=NULL;
        new->prev=ptr;
        head=new;
        printf("Do you want to add more values? (y,n) \n");
        scanf(" %c",&ch);
    }

    ptr=head;
    while(ptr!=NULL)
    {
        printf("Element: %d\n",ptr->data);
        ptr=ptr->next;
    }
    return 0;
}