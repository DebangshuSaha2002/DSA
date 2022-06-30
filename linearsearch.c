#include<stdio.h>

int linearsearch(int arr[],int size, int element)
{
    for(int i=0;i<size;i++)
    {
        if(arr[i]==element)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    int arr[100]={12,13,62,12,87,65,35};
    int size=sizeof(arr)/sizeof(int);
    int search=62;
    int searchindex=linearsearch(arr,size,search);
    printf("The element: %d has been found at array index %d \n",search,searchindex);
    return 0;
}