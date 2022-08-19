/*Create an array and that should be dynamically insert element using the pointer. 
Use pointer to display and search the element using the pointer*/
#include<stdio.h>
#include<stdlib.h>

void insert(int *arr,int n)
{
    //Inserting elements
    printf("Enter %d values in the array :\n",n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",(arr+i));
    }
}
void display(int *arr,int n)
{
    printf("The elements u have entered are :\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\n",*(arr+i));
    }
}

    //Displaying element
void display_at_index(int *arr,int n)
{
    int index;
    printf("\nEnter the index for diaplying of the array element: ");
    scanf("%d",&index);
    if(index>n){
        printf("\nInvalid index\n");
    }
    else
    {
        printf("%d",*(arr+index));
    }
}

void searching(int *arr,int n)
{
    //Searching the element
    int num;
    int store=-1;
    printf("\nEnter the number u want to search: ");
    scanf("%d",&num);
    for(int i=0;i<n;i++)
    {
        if(*(arr+i)==num)
        {
            store=i;
        }
    }
    if(store!=-1)
    {
        printf("\nThe element is present in the array at index %d \n",store);
    }
}

int main()
{
    int n,i,j;
    printf("Enter the number of values: ");
    scanf("%d",&n);
    int *arr=(int *) malloc (n*sizeof(int));

    insert(arr,n);
    display(arr,n);
    display_at_index(arr,n);
    searching(arr,n);
    return 0;
}
