#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
void DeleteStack(stack *S);
stack *CreateStack(stack *S,int size);
void checkPalindrome(stack *S,char a[],int size);
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
void checkPalindrome(stack *S,char a[],int size)
{
    int i=0;

    while(a[i]!='X')
    {
        Push(S,a[i]);
        i++;
    }
    i++;
    while(a[i] )
    {
        if(a[i]==Pop(S))
        {
            i++;
        }
        else
        {
            printf("\nNot Palindrome!!!");
            return;
        }
    }
    if(isEmptyStack(S))
        printf("\nPalindrome!!!");
}

int main()
{
  printf("############ WELCOME TO STACK OPERATIONS ############# \n \n");
  int i=0;
  int size=0;
  stack *S=(stack*)malloc(sizeof(stack));
  char a[100];
  printf("Enter the string: ");
  scanf("%s",a);
  size=strlen(a);
  CreateStack(S,size);
  checkPalindrome(S,a,size);

  return 0;
}



