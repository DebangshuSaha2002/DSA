#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

void linkedListTraversal(struct node* ptr)
{
    while(ptr!=NULL)
    {
        printf("Element: %d \n", ptr->data);
        ptr=ptr->next;
    }
}

//Case 1
struct node * insertAtFirst(struct node *head, int data){
    struct node * ptr = (struct node *) malloc(sizeof(struct node));
    ptr->data = data;
 
    ptr->next = head;
    return ptr; 
}

// Case 2
struct node * insertAtIndex(struct node *head, int data, int index){
    struct node * ptr = (struct node *) malloc(sizeof(struct node));
    struct node * p = head;
    int i = 0;
 
    while (i!=index-1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

// Case 3
struct node * insertAtEnd(struct node *head, int data){
    struct node * ptr = (struct node *) malloc(sizeof(struct node));
    ptr->data = data;
    struct node * p = head;
 
    while(p->next!=NULL){
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}

// Case 4
struct node * insertAfterNode(struct node *head, struct node *prevNode, int data){
    struct node * ptr = (struct node *) malloc(sizeof(struct node));
    ptr->data = data;
 
    ptr->next = prevNode->next;
    prevNode->next = ptr;
 
    return head;
}

int main()
{
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;
    struct node *fifth;

    head=(struct node *)malloc(sizeof(struct node));
    second=(struct node *)malloc(sizeof(struct node));
    third=(struct node *)malloc(sizeof(struct node));
    fourth=(struct node *)malloc(sizeof(struct node));
    fifth=(struct node *)malloc(sizeof(struct node));

    head->data=7;
    head->next=second;

    second->data=14;
    second->next=third;

    third->data=21;
    third->next=fourth;

    fourth->data=28;
    fourth->next=fifth;

    fifth->data=35;
    fifth->next=NULL;
    
    printf("Linked list before insertion\n");
    linkedListTraversal(head);
    // head = insertAtFirst(head, 56);
    // head = insertAtIndex(head, 56, 1);
    // head = insertAtEnd(head, 56);
    head = insertAfterNode(head, third, 45);
    printf("\nLinked list after insertion\n");
    linkedListTraversal(head);

    
    return 0;
}