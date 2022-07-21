// #include<stdio.h>
// int main()
// {
//     int arr[100],pos,c,n,value;
//     printf("Enter the size of the array: \n");
//     scanf("%d",&n);
//     printf("Enter elements in array \n");
//     for(c=0;c<n;c++)
//     scanf("%d",&arr[c]);
//     printf("Enter the location where u want to insert \n");
//     scanf("%d",&pos);
//     printf("Enter the value to be inserted\n");
//     scanf("%d",&value);
//     for(c=n-1;c>=pos;c--)
//     arr[c+1]=arr[c];
//     arr[pos-1]=value;
//     printf("The final array is\n");
//     for(c=0;c<=n;c++)
//     {
//         printf("%d\n",arr[c]);
//     }
//     return 0;
// }

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
    //inserting at a particular position
    printf("Enter the position where u want to insert\n");
    scanf("%d",&position);
    printf("Enter the value of the element\n");
    scanf("%d",&value);
    for(i=position-1;i>=0;i--)
    {
        arr[i+1]=arr[i];
    }
    arr[position-1]=value;
    //After adding element
    for(int i=0;i<=n;i++)
    {
        printf("The element at index %d is %d\n",i,arr[i]);
    }
    return 0;
}