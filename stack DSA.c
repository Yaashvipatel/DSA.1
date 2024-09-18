#include<stdio.h>
#include<stdlib.h>
#define max 10

int push(int top)
{
    int x,arr[max];
    //overflow condn: 
    if(top>=max-1)
    {
        printf("\nstack overflow ");
    }
    else
    {
        printf("\nenter element : ");
        scanf("%d",&x);
        top= top+1;
        arr[top]=x;
    }
    return top;
}

int pop(int top)
{
    int x,arr[max];
    //underflow condn: 
    if(top==-1)
    {
        printf("\nstack empty ");
    }
    else
    {
        top= top-1;
    }
    return top;
}

int traverse(int top)
{
    int i,x,arr[max];
    //underflow condn: 
    if(top==-1)
    {
        printf("\nstack empty ");
    }
    else
    {
        for(i=0;i<=top;i++)
        {
            printf("%d\t",arr[i]);
        }
    }
    return top;
}

int main()
{
    int arr[max], top = -1 , choice ;
    printf("\nenter 1 to push , 2 to pop and 3 to traverse the stack  : \n");
    do{
        printf("\nenter choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1 : 
            top = push(top);
            break;
            case 2 :
            top = pop(top);
            break;
            case 3 :
            top = traverse(top);
            break;
            default : 
            exit(0);
        }
    } while(1);
    return 0;
}
