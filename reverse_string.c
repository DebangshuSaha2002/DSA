//Reversing a string in c

#include<stdio.h>
#include<string.h>

void revstr(char x[])
{
    int temp;
    int len=strlen(x);
    for(int i=0;i<len/2;i++)
    {
        temp=x[i];
        x[i]=x[len-i-1];
        x[len-i-1]=temp;
    }
}

int main()
{
    char str[100];
    printf("Enter the string:");
    scanf("%s",str);
    // printf("%c ",revstr(str));
    revstr(str);
    printf("%s",str);
}