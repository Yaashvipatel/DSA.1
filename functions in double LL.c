//functions in double LL.c
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data ;
    struct node *next;
    struct node *prev;//self refferencial
};

struct node *insertatbeg(struct node *head){
    struct node*temp,*ptr;
    temp= (struct node*)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("memory not available");
    }
    else
    {
        if(head==NULL)
        {
            printf("enter data : ");
            scanf("%d",&temp->data);
            temp->next = NULL;
            temp->prev = NULL;
            head = temp;
        }
        else 
        {
           temp->next=head;
           temp->prev=NULL;
           head->prev=temp;
           printf("enter data : ");
           scanf("%d",&temp->data);
           head=temp;
        }
    }
    return head;
}

struct node *dltlast(struct node *head){
    struct node *ptr1,*ptr2;
    if(head==NULL)
    {
        printf("\nno items");
    }
    else if(head->next==NULL && head->prev == NULL)
    {
        ptr1=head;
        head=NULL;
        free(ptr1);
    }
    else
    {
        ptr1=head;
        while(ptr1->next!=NULL)
        {
            ptr2=ptr1;
            ptr1=ptr1->next;
        }
        ptr2->next=NULL;
        free(ptr1);
    }
    return head;
}

struct node *display(struct node *head){
    struct node *ptr;
    if(head==NULL)
    {
        printf("\nno items");
    }
    else if(head->next==NULL && head->prev == NULL)
    {
        printf("%d",head->data);
    }
    else
    {
        ptr = head;
        while(ptr!=NULL)
        {
            printf("%d\t",ptr->data);
            ptr = ptr->next;
        }
    }
    return head;
}



int main(){
    struct node * head =NULL;
    int choice;
    printf("press 1 to insert , press 2 to dlt last ,  and 8 to display ,9 to exit : ");
    do{
        printf("\nenter choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 : 
            head = insertatbeg(head);
            break;
            case 2 :
            head = dltlast(head);
            case 8: 
            head = display(head);
            break;
            case 9 :
            exit(0);
            default : 
        }
    }while(1);
    return 0;
}
