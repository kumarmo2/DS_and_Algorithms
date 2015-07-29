/*   ##############  INSERTION SORT  ########## */


#include<stdio.h>

void main()
{
  int j=0,key=0,i=0;
  int A[]={10,9,8,7,6,5,4,3,2,1};
  printf("Before sorting....\n");
  for(j=0;j<10;j++)
    printf("%d ",A[j]);
  for(j=1;j<10;j++)
  {
    key=A[j];
    i=j-1;
    while(i>=0 && A[i]>key)
    {
     A[i+1]=A[i];
     i--;
    }
    A[i+1]=key;
  }
  printf("\nAfter sorting....\n");
  for(j=0;j<10;j++)
    printf("%d ",A[j]);
}
