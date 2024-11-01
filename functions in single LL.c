//functions in single LL.c
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
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

struct node *countodd(struct node *head){
    int c=0;
    struct node *ptr;
    if(head==NULL)
    {
        printf("no items");
    }
    else if(head->next==NULL)
    {
        if((head->data)%2!=0)
        {
            c++;
        }
    }
    else
    {
        ptr=head;
        while(ptr!=NULL)
        {
            if((ptr->data)%2!=0)
            {
                c++;
            }
            ptr=ptr->next;
        }
    }
    printf("the odd no of data are : %d",c);
    return head;
}

struct node *findmiddle(struct node *head){
    int c=0,x;
    struct node *ptr;
    if(head==NULL)
    {
        printf("no items");
    }
    else{
        ptr=head;
        while(ptr!=NULL)
        {
            c++;
            ptr=ptr->next;
        }
       if(c%2==0)
       {
           x=c/2;
       }
       else
       {
           x=(c/2) +1;
       }
        ptr=head;
        for(int i=1;i<x;i++)
        {
            ptr=ptr->next;
        }
        printf("the middle value is : %d",ptr->data);
    }
    return head;
}


struct node *reverse(struct node *head){
    struct node *prev ,*current , *new;
    prev = NULL;
    current = new = head;
    while(new!=NULL)
        {
            new = new->next;
            current -> next = prev;
            prev = current ;
            current = new;
        }
        head = prev;
        
        //to print in reverse order :
        
        /*while(prev!=NULL)
        {
            printf("%d",prev->data);
            prev=prev->next;
        }*/
    return head;
}


struct node *search(struct node *head){
    int c=0,x;
    struct node *ptr,*ptr2;
    if(head==NULL)
    {
        printf("no items");
    }
    else{
        printf("\nenter the element to search : ");
        scanf("%d",&x);
        ptr=head;
        while(ptr!=NULL)
        {
            if(ptr->data == x)
            {
                printf("\nthe element is at position : %d", c+1);
            }
            ptr=ptr->next;
            c++;
        }
    }
    return head;
}

struct node *dltduplicate(struct node *head) {
    struct node *ptr, *ptr1, *ptr2 , *ptr3;

    if (head == NULL) {
        printf("No items in the list.\n");
        return head;
    }

    ptr=head;
    while(ptr!=NULL)
    {
        ptr1 = ptr;
        while(ptr1->next!=NULL)
        {
            if(ptr1->next->data==ptr->data)
            {
                ptr2=ptr1->next;
                ptr1->next=ptr1->next->next;
                free(ptr2);
            }
            ptr1=ptr1->next;
        }ptr=ptr->next;
    }
    return head;
}


struct node *pallindrome(struct node *head) {
    struct node *ptr, *ptr1, *ptr2 , *ptr3;
    int num=0,rev=0,c=0;
    if (head == NULL) {
        printf("No items in the list.\n");
    }

    else
    {
        ptr=head;
        while(ptr!=NULL)
        {
            c++;
            ptr=ptr->next;
        }
        ptr=head;
        while(ptr!=NULL&&c-1>=0)
        {
            num=num+((ptr->data) * pow(10,c-1));
            ptr=ptr->next;
            c--;
        }
        int z=num;
        int rem;
        while(z!=0)
        {
        rem=z%10;
        rev=rev*10+rem;
        z=z/10;
        }
        if(num==rev)
        {
            printf("\nthe link list is pallindrome");
        }
        else
        {
            printf("\nnot pallindrome");
        }
    }
    return head;
}


struct node *dlt_alternate(struct node *head) {
    struct node *p1,*p2;
    int num=0,rev=0,c=0;
    if (head == NULL) {
        printf("No items in the list.\n");
    }

    else
    {
        p1=head;
        while(p1!=NULL && p1->next != NULL)
        {
            p2=p1->next;
            p1->next=p1->next->next;
            free(p2);
            p1=p1->next;
        }
        
    }
    return head;
}

struct node *rotate(struct node *head) {
    struct node *p1,*p2;
    int num=0,rev=0,c=0;
    if (head == NULL) {
        printf("No items in the list.\n");
    }

    else
    {
        int x,i;
        printf("\nenter no : ");
        scanf("%d",&x);
        for(i=0;i<x;i++)
        {
            p1=head;
            while(p1->next!=NULL)
            {
                p2=p1;
                p1=p1->next;
            }
            p1->next = head;
            p2->next = NULL;
            head = p1;
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
    printf("press 1 to insert , press 2 to count odd , 3 to find the middle node , 4 to reverse , 5 to search , 6 to dlt duplicate , 7 to check if pallindrome ,and 8 to display ,9 to exit ,10 to dltalternate , 11 to rotate : ");
    do{
        printf("\nenter choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 : 
            head = insert(head);
            break;
            case 2: 
            head = countodd(head);
            break;
            case 3 : 
            head = findmiddle(head);
            case 4 : 
            head = reverse(head);
            case 5 : 
            head = search(head);
            break;
            case 6 : 
            head = dltduplicate(head);
            break;
            case 7 :
            head = pallindrome(head);
            break;
            case 8: 
            head = display(head);
            break;
            case 9 :
            exit(0);
            case 10: 
            head = dlt_alternate(head);
            break;
            case 11: 
            head = rotate(head);
            break;
            default : 
        }
    }while(1);
    return 0;
}
