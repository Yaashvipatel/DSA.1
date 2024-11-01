//rotate array.c 
#include<stdio.h>
int main()
{
    int x,arr[100],i=1,j,k,n,temp;
    printf("enter no of elements : ");
    scanf("%d",&n);
    printf("enter array elements : \n");
    for(j=0;j<n;j++)
    {
        scanf("%d",&arr[j]);
    }
    printf("enter no of rotations : ");
    scanf("%d",&x);
    
    //for(j=0;j<n;j++)
    //{
        while(i<=x)
        {
            //temp=arr[j];
            temp=arr[0];
            for(k=0;k<n;k++)
            {
                arr[k]=arr[k+1];
            }
            arr[n-1]=temp;
            i++;
        }
    //}
    
    printf("array after rotation is : \n");
    for(j=0;j<n;j++)
    {
        printf("%d\t",arr[j]);
    }
}
 
