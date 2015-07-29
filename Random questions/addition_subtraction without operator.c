#include<stdio.h>
int sub(int ,int );
int sum (int ,int );

void main ()
{
    int x,y,res1,res2=0;
    printf("Enter two numbers for addition and subtraction:");
    scanf("%d %d",&x,&y);
    res1=sum(x,y);
    res2=sub(x,y);
    printf("The sum is %d \n",res1);
    printf("The sub is %d",res2);
}

int sum (int x,int y)
{
  int carry=0;

   while(y!=0)
   {
     carry=x & y;
     x=x^y;
     y=carry <<1;
   }
   return x;
}

int sub (int x,int y)
{
  int borrow=0;

   while(y!=0)
   {
     borrow=(~x) & y;
     x=x^y;
     y=borrow <<1;
   }
  return x;
}
