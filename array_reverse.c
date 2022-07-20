#include<stdio.h>
int main()
{
    int arr[100];
    int size,i;
    printf("Enter the size of the array: \n");
    scanf("%d",&size);
    printf("Enter elements in array \n");
    for(i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("\nArray in reverse order : \n");
    for(i=size-1;i>=0;i--)
    {
        printf("%d\n",arr[i]);
    }
    return 0;
}