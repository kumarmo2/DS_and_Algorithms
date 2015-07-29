#include<stdio.h>
void main()
{
  int a[5]={1,2,1,3,2};
  int i,res;
  for(i=res=0;i<5;i++)
  {
    res=res^a[i];
  }
     printf("test\n");
  printf("The non-repeating element is %d",res);
}
