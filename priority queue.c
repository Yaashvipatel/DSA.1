//priority queue: 
/*Program to implement an Ascending Priority Queue using Static Memory Allocation 
  and call by value.
  Ascending Priority Queue = Least Value has Highest Priority hence dequeued first */
#define max 10
#include<stdio.h>
int PEnqueue(int[], int);
void PDequeue(int[], int);
void display(int[], int);
int main()
 {
  int PQ[max], r=0, ch;
  do
   {
    printf("\nFor an ASCENDING PRIORITY QUEUE.");
    printf("\nEnter: 1 to Enqueue \n       2 to Dequeue");
    printf("\n       3 to Display\n");
    printf("\nEnter your choice.\n");
    scanf("%d",&ch);
    switch(ch)
     {
      case 1:
        r = PEnqueue(PQ, r);
       break;
      case 2:
        PDequeue(PQ,r);
        r=0;
       break;
      case 3:
        display(PQ,r);
       break;
      default:
        printf("\nInvalid Operation.\n");
     }
   }while(ch>0 && ch<5);
  return 0;
 }

int PEnqueue(int PQ[], int r)
 {
  int pri, x;
  if(r>=max-1) printf("\nQueue is full.\n");
  else
   {
    printf("\nInput priority and value.\n");
    scanf("%d %d",&pri,&x);
    PQ[r] = pri;
    PQ[1+r] = x;
    r+=2;
   }
  return r;
 }

void PDequeue(int PQ[], int r)
 {
  int i, j, min, p;
  if(r==0) 
   {
    printf("\nQueue is empty\n");
    return;
   }
  for(i=0; i<r-1; i+=2)
   {
    min = PQ[i];
    p = i;
    for(int j=0; j<=r-2; j+=2)
     {
      if(min>PQ[j])
       {
        min = PQ[j];
        p = j;
       }
     }
    printf("\nPriority: %d;  Value: %d.\n",min,PQ[p+1]);
    PQ[p] = 999;
   }
  return;
 }

void display(int PQ[], int r)
 {
  if(r==0) printf("\nQueue is empty.\n");
  else 
   {
    printf("\nPriority\tValue\n");
    int j=0;
    while(j<r-1)
     {
      printf("  %d \t\t %d\n",PQ[j],PQ[j+1]);
      j+=2;
     }
   }
 }
