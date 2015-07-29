#include<stdio.h>
int expoential(int k,int n);

int exponential(int k,int n)
{
int a;
  if(k==0)
    return 0;
  if(n==0)
    return 1;
  if(n%2==1)
  {
    a=exponential(k,n-1);
    return a*k;
  }
  else
  {
    a=exponential(k,n/2);
    return a*a;
  }
}

void main()
{
  printf("Calculating the value of k power n !!!!!!!");
  int k,n;
  printf("\nEnter the value of k = ");
  scanf("%d",&k);
  printf("\nEnter the value of n = ");
  scanf("%d",&n);
  printf("\nThe value of k power n = %d",exponential(k,n));
}
