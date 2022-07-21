#include<stdio.h>
int main()
{
    int i,j;
    int n=0;
    int arr[100];
    int value;
    int found;
    int index;
    printf("Enter the number of elements: \n");
    scanf("%d",&n);
    printf("Enter %d elements\n",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("The Original array elements are:\n");
    for(i=0;i<n;i++)
    {
        printf("%d\n",arr[i]);
    }
    printf("Enter the element you want to serach in the array\n");
    scanf("%d",&value);
    for(i=0;i<n;i++)
    {
        if(arr[i]==value)
        {
            found=1;
            index=i;
            break;
        }
        else
        {
            found=0;
        }
    }
    if(found==0)
    {
        printf("Element is not in the array\n");
    }
    printf("The array is found at index %d \n",i);
    return 0;
}