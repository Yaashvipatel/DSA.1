//OPTIMISED BUBBLE SORTING 
//best case scenario: when array is already sorted , then no of passes will be : 1 , and the time complexity would be : O(n);
//worst case scenario: when array is descending , then no of passes will be : n-1 , and the time complexity would be : O(n^2);


#include<stdio.h>
#define max 10
int main()
{
    int arr[max],temp,n,i,j,f;
    printf("enter n : ");
    scanf("%d",&n);
    printf("\nenter elements : ");
    for(i=0;i<n;i++)
    {
        printf("\nelement : ");
        scanf("%d",&arr[i]);
    }
    //applying sorting : 
    for(i=0;i<n-1;i++)//no of passes loop
    {
        f=0;
        for(j=0;j<n-1-i;j++)//no of comparisions loop
        {
            if(arr[j]>arr[j+1])
            {
                temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                f=1;
            }
        }
        
        if(f==0)
        {
            printf("\narray sorted");
            break;
        }
    }
    printf("\n");
    for(i=0;i<n;i++)
    {
        printf("%d",arr[i]);
    }
    return 0;
}
