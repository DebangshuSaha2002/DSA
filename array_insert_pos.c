#include<stdio.h>
int main()
{
    int arr[100],pos,c,n,value;
    printf("Enter the size of the array: \n");
    scanf("%d",&n);
    printf("Enter elements in array \n");
    for(c=0;c<n;c++)
    scanf("%d",&arr[c]);
    printf("Enter the location where u want to insert \n");
    scanf("%d",&pos);
    printf("Enter the value to be inserted\n");
    scanf("%d",&value);
    for(c=n-1;c>=pos;c--)
    arr[c+1]=arr[c];
    arr[pos-1]=value;
    printf("The final array is\n");
    for(c=0;c<=n;c++)
    {
        printf("%d\n",arr[c]);
    }
    return 0;
}