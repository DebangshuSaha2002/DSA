#include<stdio.h>
int main()
{
    int i,j;
    int n;
    int arr[100];
    int position;
    int value;
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    printf("Enter %d elements\n",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("\n");
    printf("The elements u have entered are:\n");
    for(j=0;j<n;j++)
    {
        printf("\nThe element at index %d is %d\n",j,arr[j]);
    }

    printf("Enter the position where u want to delete an element: ");
    scanf("%d",&position);
    if(position>n-1)
    {
        printf("This deletion is not possible\n");
    }
    else{
        for(i=position-1;i<n-1;i++)
        {
            arr[i]=arr[i+1];
        }
    }
        printf("\nArray after deletion\n");
        for(j=0;j<n-1;j++)
        {
            printf("%d\n",arr[j]);
        }
    return 0;
}
