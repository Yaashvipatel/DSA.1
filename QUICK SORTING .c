//QUICK SORTING 
//quick sorting is based on the concept of divide and conquer , a pivot element is set (generally the first) to whom's left we put the values less than that and at the right the values greater than pivot .
//then the partion takes place and recursively keeps calling the parts tille array is sorted.
//best case or avg case scenario: the time complexity would be : O(nlogn);
//worst case scenario: when array is descending , the time complexity would be : O(n^2);
//no. of passes = n -1 

#include<stdio.h>
#define max 10

int partition(int arr[] , int lb, int ub)
{
    int temp;
    int pivot = arr[lb];
    int start = lb;
    int end = ub;
    while(start < end)
    {
        while(arr[start]<= pivot && start< ub)
        {
            start ++;
        }
        while(arr[end]>pivot && end>lb)
        {
            end--;
        }
        if(start < end)
        {
            temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
        }
    }
    temp = arr[lb];
    arr[lb] = arr[end];
    arr[end] = temp;
    return end;
}

void quick_sort(int arr[],int lb , int ub)//sorting function
{
    if(lb<ub)
    {
        int loc = partition(arr , lb , ub);
        quick_sort(arr , lb , loc-1);//recursive calls 
        quick_sort(arr , loc+1 , ub);
    }
}

int main()
{
    int arr[max],n,i,j,min;
    printf("enter n : ");
    scanf("%d",&n);
    printf("\nenter elements : ");
    for(i=0;i<n;i++)
    {
        printf("\nelement : ");
        scanf("%d",&arr[i]);
    }
    //applying sorting :
    quick_sort(arr,0,n-1);//calling the sorting function
    printf("\n");
    for(i=0;i<n;i++)
    {
        printf("%d",arr[i]);
    }
    return 0;
}
