//check ap;
#include<stdio.h>
int main()
{
    int arr[100],i,n,f=0,d;
    printf("enter n : ");
    scanf("%d",&n);
    printf("enter elements : ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    d=arr[1]-arr[0];
    for(i=0;i<n-1;i++)
    {
        if(arr[i+1]-arr[i]!=d)
        {
            f=1;
            break;
        }
    }
    if(f==0)
    printf("this is AP series");
    if(f==1)
    printf("this is not an AP series");
    return 0;
}
