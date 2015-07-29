#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

struct ArrayStack
{
  int top;
  int size;
  char *array;
};
typedef struct ArrayStack stack;

int isEmptyStack(stack *S);
int isFullStack(stack *S);
void Push(stack *S,char data);
char Pop(stack *S);
stack *CreateStack(stack *S,int size);
void check(stack *S,char arr[],int size);

int flag=0;

stack *CreateStack(stack *S,int size)
{

  if(!S)
     return NULL;

  S->size=size;
  S->top=-1;
  S->array=(char* )malloc((S->size) * (sizeof(char)));
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

void Push(stack *S,char data)
{
    if(isFullStack(S))
        printf("Stack is full !!!!  Cannot insert new element\n ");
    else
        S->array[++S->top]=data;
}

char Pop(stack *S)
{
    if(isEmptyStack(S))
    {
        return '\0';
    }
        return S->array[S->top--];
}

void check(stack *S,char arr[],int size)
{
  int j=0;

while(j<size)
{

 if(arr[j]== '{')
 {
      Push(S,arr[j]);
 }
 else
 {
    char ch=Pop(S);
     if(ch!= '{')
     {
          printf("Paranthesis are imbalanced\n");
          exit(0);
     }
  }
 j++;
 }

 if(isEmptyStack(S))
    printf("Paranthesis are balanced");
 else
   printf("Paranthesis are imbalanced");
}

void main()
{
  int i=0;
  stack *S=(stack*)malloc(sizeof(stack));

printf("#########    Welcome to Paranthesis balance checking {{{  }}}  ########\n \n");

*CreateStack(S,MAX);
char ch[MAX];

int size=0;

char c;
printf("Enter your lines (Press 0 to exit) :  ");
while(1)
{
    char c=getchar();
    if(c== '{' || c=='}' )
       {
       size++;
       ch[i++]=c;
       }
    else if(c=='0')
        break;
}

check(S,ch,size);

}





