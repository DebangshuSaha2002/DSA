#include<stdio.h>
int main()
{
    int i,j;
    int n=0;
    int arr[100];
    int value;
    int found;
    int index;
    int c;
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
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(arr[i]>arr[j])
            {
                c=arr[i];
                arr[i]=arr[j];
                arr[j]=c;
            }
        }
    }
    printf("The sorted array elements in ascending order is: \n");
    for(i=0;i<n;i++)
    {
        printf("%d\n",arr[i]);
    }
    return 0;
}