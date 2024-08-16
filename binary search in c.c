//binary search in c.c :
#include<stdio.h>
int main()
{
    int middle ,x, first, last ,arr[100],n,i;
    printf("enter no of elements : ");
    scanf("%d",&n);
    printf("enter element to search : ");
    scanf("%d",&x);
    printf("enter elements :\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);//input elements
    }
    first=0 , last=n-1 , middle=(first + last)/2;
    while(first<=last)//condition for element to be present in the given array
    {
        if(arr[middle]==x)
        {
            printf("element is found at location %d",middle +1);
            break;
        }
        else if(arr[middle]<x)//that means element is prersent at second half of the array
        {
            first = middle +1 ;
        }
        else//that means element is prersent at first half of the array
        {
            last = middle -1 ;
        }
        middle = (first+ last )/2;
    }
    if(first>last)
    {
        printf("the element does not exist in the given array");
    }
    return 0;
}
