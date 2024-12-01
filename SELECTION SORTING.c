//SELECTION SORTING 
//selection sorting is a techinique having two sublists : 1 is sorted(which is initially having 0 elements ) and another is unsroted , minimum element of unsorted is extracted and swapped with the starting element of unsorted list and is included in sorted list .
//best case scenario: when array is already sorted , the time complexity would be : O(n);
//worst case scenario: when array is descending , the time complexity would be : O(n^2);
//no. of passes = n -1 

#include<stdio.h>
#define max 10
int main()
{
    int arr[max],temp,n,i,j,min;
    printf("enter n : ");
    scanf("%d",&n);
    printf("\nenter elements : ");
    for(i=0;i<n;i++)
    {
        printf("\nelement : ");
        scanf("%d",&arr[i]);
    }
    //applying sorting : 
    for(i=0;i<n-1;i++)//this loop is for no of passes 
    {
        min = i ;
        for(j = i+1 ;j<n;j++ )//this loop finds minimum
        {
            if(arr[j]<arr[min])
            {
                min = j;
            }
        }
        if(min != i)
        {
            temp = arr[i];
            arr[i]=arr[min];
            arr[min]=temp;
        }
    }
    printf("\n");
    for(i=0;i<n;i++)
    {
        printf("%d",arr[i]);
    }
    return 0;
}
