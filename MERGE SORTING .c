//MERGE SORTING 
//merge sorting is based on the concept of divide and conquer , the list is divided till each sub list has one element int it and then one by one adjacent lists are being merged so that in the end we get a final sorted list.
//then the partion takes place and recursively keeps calling the parts tille array is sorted.
//best case or avg case scenario: the time complexity would be : O(nlogn);
//worst case scenario: when array is descending , the time complexity would be : O(nlogn);
//merging complexity is : theeta(m+n)(m=elememts of one sublist and n = elements of another sublist)

#include<stdio.h>
#define max 10

void merge(int arr[] , int lb, int mid ,int ub)
{
    int brr[max];
    int k;
    int i;
    int j;
    i = lb;
    j = mid +1;
    k = lb;
    while(i<= mid && j<=ub)
    {
        if(arr[i]<=arr[j])
        {
            brr[k++] = arr[i++];
        }
        else
        {
            brr[k++] = arr[j++];
        }
    }
    if(i>mid)
    {
        while(j<=ub)
        {
            brr[k++] = arr[j++];
        }
    }
    
    else
    {
        while(i<=mid)
        {
            brr[k++] = arr[i++];
        }
    }
    
    for(k=lb ; k<= ub ; k++)
    {
        arr[k] = brr[k];
    }
}

void merge_sort(int arr[],int lb , int ub)//sorting function
{
    int mid;
    if(lb<ub)
    {
        mid = (lb+ub)/2;
        merge_sort(arr , lb , mid);
        merge_sort(arr , mid+1 , ub);//recursive calls 
        merge(arr , lb , mid , ub);
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
    merge_sort(arr,0,n-1);//calling the sorting function
    printf("\n");
    for(i=0;i<n;i++)
    {
        printf("%d",arr[i]);
    }
    return 0;
}
