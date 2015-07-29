#include<stdio.h>
#define MAX 500
int findinfiniteseries(int a[],int k);
int findindex(int a[],int low,int high,int k);

int findinfiniteseries(int a[],int k)
{
  int low=1,high=1,mid=0;
  while(a[high]!='$' && high < 500)
  {
    low=high;
    high=high*2;
  }
  while((high-low)>1)
  {
    mid=((high-low)/2)+low;
    if(a[mid]=='$')
       high=mid;
    else
      low=mid;
  }
  return high;
}
int findindex(int a[],int low,int high,int k)
{
  int mid=0;
  if(low<high)
  {
      mid=(high+low)/2;
      if(a[mid]==k)
        return mid;
      else if(a[mid]>k)
         return findindex(a,low,mid-1,k);
      else
        return findindex(a,mid+1,high,k);
  }
  else if(low==high)
  {
     if(a[low]==k)
        return low;
     else
    return -1;
  }
  else
    return -1;

}

void main()
{
 int a[MAX]={0,0},k=0,i=0;
 printf("An inifinite series is created......");
 for(i=0;i<300;i++)
   a[i]=i;
 for(i=300;i<400;i++)
   a[i]='$';
 i=0;
 while(i<400)
 {
     printf("%d ",a[i++]);
 }
 printf("\nEnter the element you are searching for = ");
 scanf("%d",&k);
 int n=findinfiniteseries(a,k);
 if(findindex(a,0,n-1,k)!=-1)
   printf("\nThe element you are looking exists at index=%d",findindex(a,0,n-1,k));
 else
    printf("\nElement doesnot exists !!!");

}
