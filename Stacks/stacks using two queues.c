#include<stdio.h>
#include<stdlib.h>

struct ArrayQueue
{
    int head,tail;
    int size;
    int *array;
};
typedef struct ArrayQueue queue;

queue *CreateQueue(queue *Q,int size);
int isEmptyQueue(queue *Q);
int isFullQueue(queue *Q);
int Queuesize(queue *Q);
void Enqueue (queue *Q,int data);
int Dequeue(queue *Q);
void DeleteQueue(queue *Q);
int flag=0;

queue *CreateQueue(queue *Q,int size)
{
  if(!Q)
    return NULL;

  Q->size=size;
  Q->head=Q->tail=-1;
  Q->array=(int *)malloc(sizeof(int)*(Q->size));

  if(!Q->array)
    return NULL;
  else
  {
    flag=1;
    return Q;
  }
}

int isEmptyQueue(queue *Q)
{
    return (Q->head==-1);
}

int isFullQueue(queue *Q)
{
    return (Q->head==Q->tail+1);
}

int Queuesize(queue *Q)
{
    if (flag==1)
      return ((Q->size-Q->head+Q->tail+1)%Q->size);
    else
      return 0;
}

void Enqueue (queue *Q,int data)
{
    if(isFullQueue((Q)))
        printf("Queue is full !!! Insertion not possible !!! Queue Overflow\n");
    else
    {
        if(Q->tail==Q->size-1)
          Q->tail=0;
        else
        {
          ++Q->tail;
          Q->array[Q->tail]=data;
        }
       if(Q->head==-1)
         Q->head=Q->tail;
    }
}

int Dequeue(queue *Q)
{
    int temp=0;
    if(isEmptyQueue(Q))
        printf("Queue is empty!!!! Deletion not possible !!! Queue underflow");
    else
    {
        if(Queuesize(Q)==1)
        {
           temp=Q->head;
           Q->head=Q->tail=-1;
        }
        else if(Q->head==Q->size-1)
        {
            Q->head=0;
            temp=Q->size-1;
        }
        else
        {
            ++Q->head;
            temp=Q->head-1;
        }


    }
    return Q->array[temp];
}

void DeleteQueue(queue *Q)
{
    flag=0;
    if(Q)
    {
        if(Q->array)
            free(Q->array);
        free(Q);
    }
}
struct Stack
{
  queue *Q1;
  queue *Q2;
};
typedef struct Stack stack;

void Push(stack *S,int data)
{
    Enqueue(S->Q1,data);
}

int Pop(stack *S)
{
  int size=Queuesize(S->Q1);
  int i=0;
  while(i<size-1)
  {
        Enqueue(S->Q2,Dequeue(S->Q1));
        i++;
  }
  return Dequeue(S->Q1);
}

int main()
{
  printf("############ STACKS USING TWO QUEUES ############# \n \n");
  int i=0,j=0;
  int size=0,data=0;
  stack *S=(stack*)malloc(sizeof(stack));
  S->Q1=(queue*)malloc(sizeof(queue));
  S->Q2=(queue*)malloc(sizeof(queue));
  CreateQueue(S->Q1,100);
  CreateQueue(S->Q2,100);
  printf("Enter the values(Press -1 to exit)= ");
  while(1)
  {
      scanf("%d",&i);
      if(i==-1)
        break;
      else
        Enqueue(S->Q1,i);
  }
  printf("\nEnter the new data = ");
  scanf("%d",&data);
  Push(S,data);
  size=Queuesize(S->Q1);
  printf("\nThe elements are : ");
  while(j<size)
    printf("%d ",S->Q1->array[j++]);
  printf("\nThe element after pop operation = %d",Pop(S));
  printf("\nThe elements now are : ");
  size=Queuesize(S->Q2);
  j=0;
  while(j<size)
    printf("%d ",S->Q2->array[j++]);


  return 0;
}
