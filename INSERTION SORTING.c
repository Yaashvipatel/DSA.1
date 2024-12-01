//INSERTION SORTING 
//insertion sorting is a techinique having two sublists : 1 is sorted and another is unsroted , element of unsorted is extracted and placed in the appropriate place of the sorted list .
//best case scenario: when array is already sorted , the time complexity would be : O(n);
//worst case scenario: when array is descending , the time complexity would be : O(n^2);


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
    for(i=0;i<n;i++)//this loop traces unsroted sublist from left to right
    {
        temp = arr[i];
        j=i-1;
        while(j>=0 && arr[j]>temp)//this loop traces sorted list from right to left
        {
            arr[j+1] = arr[j];
            j--;//decrementing loop
        }
        
        arr[j+1] = temp; //assigning apt value to temp in sorted lsit
    }
    printf("\n");
    for(i=0;i<n;i++)
    {
        printf("%d",arr[i]);
    }
    return 0;
}
