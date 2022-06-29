#include<stdio.h>

void display(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

// int insertion(int arr[],int size,int element, int capacity,int index)
// {
//     if(size>capacity)
//     {
//         return -1;
//     }
//     for(int i=size-1;i>=index;i--)
//     {
//         arr[i+1]=arr[i];
//     }
//     arr[index]=element;
//     return 1;
// }

void deletion(int arr[],int size, int index)
{
    for(int i=index;i<=size-1;i++)
    {
        arr[i]=arr[i+1];
    }
}

int main()
{
    int arr[100]={12,13,14,15,76,21,53,18};
    int size=8;
    int index=2;
    int capacity=100;
    int element=32;
    display(arr,size);
    // // insertion
    // insertion(arr,size,element,capacity,index);
    // size+=1;
    // display(arr,size);

    //deletion
    deletion(arr,size,index);
    size-=1;
    display(arr,size);

    return 0;
}