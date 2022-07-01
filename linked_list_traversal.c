// #include<stdio.h>
// #include<stdlib.h>

// struct Node{
//     int data;
//     struct Node *next;
// };

// void linkedListTraversal(struct Node *ptr)
// {
//     while(ptr!=NULL)
//     {
//         printf("Element %d \n",ptr->data);
//         ptr=ptr->next;
//     }
// }

// int main()
// {
//     struct Node *head;
//     struct Node *second;
//     struct Node *third;
//     struct Node *fourth;

//     //allocate memory for nodes in the linked list in HEAP
//     head=(struct Node *)malloc(sizeof(struct Node));
//     second=(struct Node *)malloc(sizeof(struct Node));
//     third=(struct Node *)malloc(sizeof(struct Node));
//     fourth=(struct Node *)malloc(sizeof(struct Node));

//     //Link first and second nodes
//     head->data=7;
//     head->next=second;

//     //Link second and third nodes
//     second->data=11;
//     second->next=third;

//     //Link third and fourth nodes
//     third->data=23;
//     third->next=fourth;

//     //terminating the fourth node
//     fourth->data=55;
//     fourth->next=NULL;

//     linkedListTraversal(head);
//     return 0;
// }

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

void LinkedListTraversal(struct node* ptr)
{
    while(ptr!=NULL)
    {
        printf("Element: %d \n", ptr->data);
        ptr=ptr->next;
    }
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

    LinkedListTraversal(head);
    {
        /* data */
    };
    
    return 0;
}