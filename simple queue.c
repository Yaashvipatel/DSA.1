
#include<stdio.h>
#include<stdlib.h>
#define max 10

void enqueue(int arr[] , int * front , int *rear)
{
    int x;
    //overflow
    if(*rear >= max -1 )
    {
        printf("\nqueue is full");
    }
    else if(*rear == -1)
    {
        *front = *rear = 0;
        printf("\nenter element ");
        scanf("%d",&x);
        arr[*rear]= x;
    }
    else
    {
        printf("\nenter element ");
        scanf("%d",&x);
        *rear= *rear +1 ;
        arr[*rear]= x;
    }
}

void dequeue(int arr[] , int * front , int *rear)
{
    int x;
    //underflow
    if(*front == -1)
    {
        printf("\nqueue is empty");
    }
    else if(*rear == *front)
    {
        *front = *rear = -1;
    }
    else
    {
        *front = *front +1;
    }
}

void traverse(int arr[] , int * front , int *rear)
{
    int x , i;
    //underflow
    if(*front == -1)
    {
        printf("\nqueue is empty");
    }
    else 
    {
        for(i=*front;i<=*rear;i++)
        {
            printf("%d",arr[i]);
        }
    }
}

int main()
{
    int front , rear , arr[max] , choice ;
    front = rear = -1;
    printf("enter 1 to push , 2 to pop and 3 to traverse : ");
    do{
        printf("\nenter choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 :
            enqueue(arr , &front , &rear);
            break;
            case 2 : 
            dequeue(arr , &front , &rear);
            break;
            case 3 :
            traverse(arr ,&front , &rear);
            break;
            default :
            exit (0);
        }
    }while(1);
    return 0;
}
