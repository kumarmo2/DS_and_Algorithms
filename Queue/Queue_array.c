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
      return NULL;
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
int main()
{
  printf("############ WELCOME TO QUEUE OPERATIONS ############# \n \n");
  int i=0;
  int size=0,data=0;
  queue *Q=(queue *)malloc(sizeof(queue));
  while(1)
  {
  printf("\n 1)Create a Queue(Press 1)\n 2)Insert an element(Press 2)\n 3)Delete an element(Press 3)\n 4)Show the Queue(Press 4)\n 5)Delete a Queue(Press 5)\n 6)Show Queue Size(Press 6)\n 7)Exit(Press 7 to exit) \n");
  scanf("%d",&i);
  switch(i)
  {
    case 1:

        printf("\nEnter the size of the stack= ");
        scanf("%d",&size);
       *CreateQueue(Q,size);
       printf("Enter the values of the element (Press -1  to stop)= \n");
       while(1)
       {

          scanf("%d",&data);
          if(data==-1)
              break;
          else
              Enqueue(Q,data);
       };
       break;

    case 2:
          printf("\nEnter the value of the element= ");
          scanf("%d",&data);
          if(data==-1)
              break;
          else
              Enqueue(Q,data);
        break;

    case 3:
          printf("The element deleted is =%d\n",Dequeue(Q));
          break;
    case 4:
       if (flag==1)
       {
        if(!isEmptyQueue(Q))
        {
          printf("\nThe elements of the Queue are: ");
          for(i=Q->head;i<=Q->tail;i++)
            printf("%d ",Q->array[i]);
          printf("\n");
        }
        else
            printf("Queue is empty !!!! \n");
       }
      else
        printf("There is no Queue !!! \n");
          break;
    case 5:
          DeleteQueue(Q);
          printf("Queue is deleted !!! \n");
          break;
    case 6:
          printf("The Queue size is = %d\n",Queuesize(Q));
          break;
    case 7:
          exit(0);
    default:
          printf("Invalid option \n");
          break;
   }
  }

 return 0;
}
