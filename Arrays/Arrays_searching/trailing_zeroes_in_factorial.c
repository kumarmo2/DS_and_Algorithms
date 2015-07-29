#include<stdio.h>
void main()
{
  int n=0,count=0,i=0;
  printf("Enter the number whose factorial you want to analyse = ");
  scanf("%d",&n);
  if(n<5)
     {
         printf("\nThe number of trailing zeroes in the factorial of %d is %d",n,count);
         return;
     }
  for(i=5;n/i>0;i*=5)
      count+=n/i;
  printf("\nThe number of trailing zeroes in the factorial of %d is %d",n,count);
}
