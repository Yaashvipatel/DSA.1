//linked list deletion(A)
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data ;
    struct node *next;//self refferencial
};

struct node *insert(struct node *head){
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
            head = temp;
        }
        else 
        {
            ptr=head;
            while(ptr->next!=NULL)
            {
                ptr=ptr->next;
            }
                ptr->next=temp;
                temp->next = NULL;
                printf("enter data : ");
                scanf("%d",&temp->data);
        }
    }
    return head;
}

struct node *dltatbeg(struct node *head){
    struct node*temp,*ptr1,*ptr2,*ptr3,*ptr4,*ptr;
    if(head==NULL)
    {
        printf("list is empty");
    }
    else if(head->next==NULL)
    {
        ptr=head;
        head=NULL;
        free(ptr);
    }
    else
    {
        ptr=head;
        head=head->next;
        free(ptr);
    }
return head;
}

struct node *dltatlast(struct node *head){
   struct node*temp,*ptr1,*ptr2,*ptr3,*ptr4,*ptr;
    if(head==NULL)
    {
        printf("list is empty");
    }
    else if(head->next==NULL)
    {
        ptr=head;
        head=NULL;
        free(ptr);
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

struct node *dltafter(struct node *head){
   
}

struct node *dltbefore(struct node *head){

}

struct node *dltseclast(struct node *head){
    struct node*temp,*ptr1,*ptr2,*ptr3,*ptr4,*ptr;
    if(head==NULL)
    {
        printf("list is empty");
    }
    else if(head->next==NULL)
    {
        ptr=head;
        head=NULL;
        free(ptr);
    }
    else
    {
        ptr1=head;
        ptr3=head;
        while(ptr1->next !=NULL)
        {
            ptr2=ptr1;
            ptr1=ptr1->next;
        }
        while(ptr3->next!=ptr1)
        {
            ptr4=ptr3;
            ptr3=ptr3->next;
        }
        ptr4->next=ptr1;
        free(ptr2);
    }
return head;
}

struct node *dltatpos(struct node *head){
    struct node*temp,*ptr1,*ptr2,*ptr3,*ptr4,*ptr;
    printf("enter the pos from where to dlt : ");
    int x;int i;
    scanf("%d",&x);
    if(x==0)
    {
    }
    else if(x==1)
    {
        head = dltatbeg(head);
    }
    else
    {
        ptr1=head;
        for(i=1;i<x;i++)
        {
            ptr2=ptr1;
            ptr1=ptr1->next;
        }
        if(ptr1->next==NULL)
        {
            head = dltatlast(head);
        }
        else
        {
           ptr2->next=ptr1->next;
           free(ptr1);
        }
    }
return head;
}

struct node *display(struct node *head){
    struct node *ptr;
    if(head==NULL)
    {
        printf("\nno items");
    }
    else if(head->next == NULL)
    {
        printf("%d",head->data);
    }
    else
    {
        ptr = head;
        while(ptr)
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
    printf("press 1 to dlt at beginning , 2 to dlt at last , 3 to dlt after a node ,4 to dlt before a node ,5 to dlt second last , 6 to dlt at nth pos ,7 to display ,8 to insert and 9 to exit : ");
    do{
        printf("\nenter choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 : 
            head = dltatbeg(head);
            break;
            case 2: 
            head = dltatlast(head);
            break;
            case 3 : 
            head = dltafter(head);
            break;
            case 4 : 
            head = dltbefore(head);
            break;
            case 5 : 
            head = dltseclast(head);
            break;
            case 6 : 
            head = dltatpos(head);
            break;
            case 7 :
            head = display(head);
            break;
            case 8: 
            head = insert(head);
            case 9 :
            exit(0);
            default : 
        }
    }while(1);
    return 0;
}
