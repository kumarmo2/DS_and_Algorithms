#include<stdio.h>

int findpivot(int a[],int low,int high)
{
    if(low<=high)
    {
      if(low==high)
         return low;
      else if(low==high-1)
         return a[low]>a[high]?low:high;
      else
      {
         int mid=(low+high)/2;
         if(a[low]<=a[mid])
            return findpivot(a,mid,high);
         else
            return findpivot(a,low,mid);
      }
    }
    else
        return -1;
}

int search(int a[],int low,int high,int data)
{
    int pivot=findpivot(a,low,high);
    if(a[pivot]==data)
        return pivot;
    else if(a[low]<=data)
        return Binarysearch(a,low,pivot-1,data);
    else
        return Binarysearch(a,pivot+1,high,data);
}

int Binarysearch(int a[],int low,int high,int data)
{
    if(low<=high)
    {
        int mid=(low+high)/2;
       if(a[mid]==data)
         return mid;
       else if(a[mid]>data)
         return Binarysearch(a,low,mid-1,data);
       else
         return Binarysearch(a,mid+1,high,data);
    }
    else
        return -1;
}
void main()
{
  int a[10]={6,7,8,9,10,1,2,3,4,5};
  int res=search(a,0,9,8);
  if(res==-1)
    printf("The number is not present");
  else
    printf("The index is %d",res);
}


