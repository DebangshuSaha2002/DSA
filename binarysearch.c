//Binary search
#include<stdio.h>
int Binarysearch(int arr[],int size)
{
    int element;
    printf("Enter the element to be searched \n");
    scanf("%d ",&element);
    int low,mid,high;
    low=0;
    high=size-1;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(arr[mid]==element)
        {
            return mid;
        }
        else if(arr[mid]<element)
        {
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return -1;
}

int main()
{
    int arr[]={12,13,16,87,45,87};
    int size=sizeof(arr)/sizeof(int);
    int searchindex=Binarysearch(arr,size);
    printf("The element is found at index %d \n",searchindex);
    return 0;
}
