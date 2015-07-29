#include<stdio.h>
int search(int a[],int n);

int search(int a[],int n)
{
  int first=0,last=n-1;
  int mid=0;
  while(first<=last)
  {
    mid=first+(last-first)/2;
    if(a[mid-1]<0 && a[mid]>0)
       return mid;
    else if(a[mid-1]<0 && a[mid]<0)
       first=mid+1;
    else
       last=mid-1;
  }
  return -1;
}

void main()
{
  int a[10]={-9,-8,-4,-3,1,2,7,8,9,10};
  int res=search(a,10);
  if(res!=-1)
    printf("The first positive index is %d",res);
  else
    printf("There is no positive numbers");
}
