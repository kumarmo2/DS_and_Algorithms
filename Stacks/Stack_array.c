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

int main()
{
  printf("############ WELCOME TO STACK OPERATIONS ############# \n \n");
  int i=0;
  int size=0,data=0;
  stack *S=(stack*)malloc(sizeof(stack));
  while(1)
  {
  printf("\n 1)Create a Stack(Press 1)\n 2)Insert an element(Press 2)\n 3)Delete an element(Press 3)\n 4)Show the stack(Press 4)\n 5)Delete a Stack(Press 5)\n 6)Exit(Press 6 to exit) \n");
  scanf("%d",&i);
  switch(i)
  {
    case 1:

        printf("\nEnter the size of the stack= ");
        scanf("%d",&size);
       *CreateStack(S,size);
       printf("Enter the values of the element (Press -1  to stop)= \n");
       while(1)
       {

          scanf("%d",&data);
          if(data==-1)
              break;
          else
              Push(S,data);
       }
       break;

    case 2:
          printf("\nEnter the value of the element= ");
          scanf("%d",&data);
          if(data==-1)
              break;
          else
              Push(S,data);
        break;

    case 3:
          printf("The element deleted is =%d\n",Pop(S));
          break;
    case 4:
       if (flag==1)
       {
        if(!isEmptyStack(S))
        {
          printf("\nThe elements of the stack are: ");
          for(i=0;i<=S->top;i++)
            printf("%d ",S->array[i]);
          printf("\n");
        }
        else
            printf("Stack is empty !!!! \n");
       }
      else
        printf("Stack is not created !!! \n");
          break;
    case 5:
          DeleteStack(S);
          printf("Stack is deleted !!! \n");
          break;
    case 6:
          exit(0);
    default:
          printf("Invalid option \n");
          break;
   }
  }

 return 0;
}



