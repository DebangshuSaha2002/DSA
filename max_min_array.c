#include<stdio.h>
int main()
{
    int i,j;
    int n=0;
    int arr[100];
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
    int max;
    int min;
    max=arr[0];
    min=arr[0];
    for(i=0;i<n;i++)
    {
        if(arr[i]>max)
        {
            max=arr[i];
        }
        if(arr[i]<min)
        {
            min=arr[i];
        }
    }
    printf("\nThe max element in the array: %d\n",max);
    printf("\nThe min element in the array: %d\n",min);
    return 0;
}