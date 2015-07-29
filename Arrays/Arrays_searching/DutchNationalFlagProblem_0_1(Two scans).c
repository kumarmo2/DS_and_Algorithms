#include<stdio.h>
void main()
{
  int a[10]={0,1,0,0,1,1,1,1,0,1};
  int count=0,i=0;
  printf("Before Separation: ");
  for(i=0;i<10;i++)
       printf("%d ",a[i]);
  i=0;
  while(i<10)
  {
    if(a[i]==0)
      count++;
    i++;
  }
  printf("\nAfter Separation: ");
  for(i=0;i<10;i++)
  {
    if(i<count)
      printf("0 ");
    else
      printf("1 ");
  }

}
