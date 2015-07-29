#include<stdio.h>

void main()
{
  int i,a[10]={1111,1110,1101,1011,1000,0010,0000,0001,0101,0111};

  for(i=0;i<10;i=i+2)
  {
    if(a[i]==0)
      {
        printf("The index from which 0's starts is %d",i);
        return ;
      }
  }
  return;
}
