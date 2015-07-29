#include<stdio.h>
#include<stdlib.h>

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
stack *CreateStack(stack *S,int size);
void moveStack(stack *S1,stack *S2);
void deQueue(stack *S1,stack *S2);

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

void deQueue(stack *S1,stack *S2)
{
    while(!isEmptyStack(S1))
    {
        Push(S2,Pop(S1));
    }
}

void moveStack(stack *S1,stack *S2)
{
    while(!isEmptyStack(S1))
    {
        Push(S2,Pop(S1));
    }
}



int main()
{
  printf("############ QUEUE USING TWO STACKS ############# \n \n");
  int i=0;
  int size=0,data=0;
  stack *S1=(stack*)malloc(sizeof(stack));
  stack *S2=(stack*)malloc(sizeof(stack));

  while(1)
  {
  printf("\n 1)Create a Stack(Press 1)\n 2)Insert an element(Press 2)\n 3)Delete an element(Press 3)\n 4)Show the stack 1(Press 4)\n 5)Implement the creation of queue using two stacks (Press 5)\n 6)Show the queue (Press 6)\n 7)Exit(Press 7 to exit) \n");
  scanf("%d",&i);
  switch(i)
  {
    case 1:

        printf("\nEnter the CAPACITY = ");
        scanf("%d",&size);
       *CreateStack(S1,size);
       *CreateStack(S2,size);
       printf("Enter the values of the element (Press -1  to stop)= \n");
       while(1)
       {

          scanf("%d",&data);
          if(data==-1)
              break;
          else
              Push(S1,data);
       }
       break;

    case 2:
          printf("\nEnter the value of the element= ");
          scanf("%d",&data);
          if(data==-1)
              break;
          else
              Push(S1,data);
        break;

    case 3:
          printf("The element deleted is =%d\n",(flag==1)?Pop(S2):Pop(S1));
          break;
    case 4:

        if(!isEmptyStack(S1))
        {
          printf("\nThe elements are: ");
          for(i=0;i<=S1->top;i++)
            printf("%d ",S1->array[i]);
          printf("\n");
        }
        else
            printf("Stack is empty !!!! \n");


          break;
    case 5:
        deQueue(S1,S2);
        flag=1;
        printf("Queue is created !!!\n");
        break;
    case 6:
        if(!isEmptyStack(S2))
        {
          printf("\nThe elements of the queue are: ");
          for(i=S2->top;i>=0;i--)
            printf("%d ",S2->array[i]);
          printf("\n");
        }
        else
            printf("Queue is empty !!!! \n");
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



