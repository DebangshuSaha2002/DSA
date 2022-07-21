#include<stdio.h>
int main()
{
    int i,j;
    int n;
    int arr[100];
    int position;
    int value;
    int found=0;
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
    printf("\nEnter the value to be deleted: ");
    scanf("%d",&value);
    for(i=0;i<n;i++)
    {
        if(arr[i]!=value)
        {
            printf("Deletion not possible\n");
        }
        else
        {
            found=1;
            position=i;
            break;
        }
    }
    if(found==1)
    {
        for(i=position;i<n-1;i++)
        {
            arr[i]=arr[i+1];
        }
        printf("The resultant array is\n");
        for(i=0;i<n-1;i++)
        {
            printf("%d\n",arr[i]);
        }

    }
    return 0;
}
