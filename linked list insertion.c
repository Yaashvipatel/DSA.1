//linked list insertion(A)
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data ;
    struct node *next;//self refferencial
};

struct node *inatbeg(struct node *head){
    struct node*temp;
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
            printf("enter data : ");
            scanf("%d",&temp->data);
            temp->next = head;
            head = temp;
        }
    }
    return head;
}

struct node *inatlast(struct node *head){
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

struct node *inafter(struct node *head){
    struct node*temp,*ptr1,*ptr2;
    int x;
    temp= (struct node*)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("memory not available");
    }
    else{
    if(head==NULL)
    {
        printf("list was empty , insertion of the node in list : ");
        printf("enter data : ");
        scanf("%d",&temp->data);
        temp->next = NULL;
        head = temp;
    }
    else
    {
        ptr1=head;
        printf("enter data value after which to be inserted : ");
        scanf("%d",&x);
        while(ptr1->data!=x)
        {
            ptr1=ptr1->next;
        }
        ptr2=ptr1->next;
        ptr1->next=temp;
        printf("enter data : ");
        scanf("%d",&temp->data);
        temp->next=ptr2;
    }
    }
    return head;
}

struct node *inbefore(struct node *head){
    struct node*temp,*ptr1,*ptr2;
    int x;
    temp= (struct node*)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("memory not available");
    }
    else{
    if(head==NULL)
    {
        printf("list was empty , insertion of the node in list : ");
        printf("enter data : ");
        scanf("%d",&temp->data);
        temp->next = NULL;
        head = temp;
    }
    else
    {
        ptr1=head;
        printf("enter data value before which to be inserted : ");
        scanf("%d",&x);
        while(ptr1->data!=x)
        {
            ptr2=ptr1;
            ptr1=ptr1->next;
        }
        ptr2->next=temp;
        temp->next=ptr1;
        printf("enter data : ");
        scanf("%d",&temp->data);
    }
    }
    return head;
}

struct node *inatpos(struct node *head){
    
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
    printf("press 1 to insert at beginning , 2 to insert at last , 3 to insert after a node ,4 to insert before a node , 5 to insert at nth pos ,6 to display and 7 to exit : ");
    do{
        printf("\nenter choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 : 
            head = inatbeg(head);
            break;
            case 2: 
            head = inatlast(head);
            break;
            case 3 : 
            head = inafter(head);
            break;
            case 4 : 
            head = inbefore(head);
            break;
            case 5 : 
            head = inatpos(head);
            break;
            case 6 :
            head = display(head);
            break;
            case 7 :
            exit(0);
            default : 
        }
    }while(1);
    return 0;
}
