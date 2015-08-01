#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct ArrayStack
{
  int top;
  int size;
  int *array;
};
typedef struct ArrayStack stack;

int isEmptyStack(stack *S);
int isFullStack(stack *S);
void Push(stack *S,int data);
int Pop(stack *S);
void DeleteStack(stack *S);
stack *CreateStack(stack *S,int size);

int flag=0;

stack *CreateStack(stack *S,int size)
{

  if(!S)
     return NULL;

  S->size=size;
  S->top=-1;
  S->array=(int* )malloc((S->size) * (sizeof(int)));
  if(!S->array)
     return NULL;
  flag=1;
  return S;
}

int isEmptyStack(stack *S)
{
    return(S->top==-1);
}

int isFullStack(stack *S)
{
    return(S->top==S->size-1);
}

void Push(stack *S,int data)
{
    if(isFullStack(S))
        printf("Stack is full !!!!  Cannot insert new element\n ");
    else
        S->array[++S->top]=data;
}

int Pop(stack *S)
{
    if(isEmptyStack(S))
    {
        printf("Stack is empty !!! Invalid deletion\n ");
        return 0;
    }

    else
        return S->array[S->top--];
}

void DeleteStack(stack *S)
{
    flag=0;
    if(S)
    {
        if(S->array)
            free(S->array);
        free(S);
    }
}
struct Queue
{
    stack *S1;
    stack *S2;
};
typedef struct Queue queue;

void Enqueue(queue *Q,int data)
{
    Push(Q->S1,data);
}

int Dequeue(queue *Q,int size)
{
    while(!isEmptyStack(Q->S1))
        Push(Q->S2,Pop(Q->S1));
    return Pop(Q->S2);
}
int main()
{
  printf("############ QUEUES USING TWO STACKS ############# \n \n");
  int i=0;
  int size=0,data=0;
  struct Queue *Q;
  Q=(queue*)malloc(sizeof(queue));
  Q->S1=(stack*)malloc(sizeof(stack));
  Q->S2=(stack*)malloc(sizeof(stack));
  CreateStack(Q->S1,100);
  CreateStack(Q->S2,100);
  printf("\nEnter the values (Press -1 to stop): ");
  while(1)
  {
     scanf("%d",&i);
     if(i==-1)
        break;
     Push(Q->S1,i);
     size++;
  }
  printf("\nEnter new data=");
  scanf("%d",&data);
  size++;
  Enqueue(Q,data);
  printf("\nThe queue elements are :");
  int j=0;
  while(j<size)
    printf("%d ",Q->S1->array[j++]);

  printf("Dequeuing the list = %d",Dequeue(Q,size));
  printf("\nThe new queue elements  are :");
  j=0;
  while(!isEmptyStack(Q->S2))
    printf("%d ",Pop(Q->S2));

  return 0;
}



