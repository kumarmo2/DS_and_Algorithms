#include<stdio.h>

int checkbitonic(int a[],int low,int high)
{
  if(low<=high)
  {
     int mid=(low+high)/2;
     if(a[mid-1]<a[mid] && a[mid]>a[mid+1])
       return 1;
     else if(a[mid-1]<a[mid] && a[mid]<a[mid+1])
       return checkbitonic(a,mid+1,high);
     else
        return checkbitonic(a,low,mid);
  }

  else
    return -1;
}

void main()
{
  int a[10]={1,2,3,4,5,6,7,8,9,10};
  //int a[10]={1,3,4,6,8,4,2,1,0,-10};
  if(checkbitonic(a,0,9)!=-1)
    printf("The given array is bitonic at %d",checkbitonic(a,0,9));
  else
    printf("The given array is not bitonic");
}
