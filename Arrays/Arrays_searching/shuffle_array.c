#include<stdio.h>
void swap(int *,int *);
void newarray(int a[],int low,int high);

void newarray(int a[],int low,int high)
{
  if(low<high)
  {
     if(low==high-1)
        return;
     else
     {
        int mid=(low+high)/2;
        int left=mid,right=mid+1;
        while(left>=(high-low)/2)
        {
           swap(&a[left],&a[right+1]);
           left--;
           right--;

        }
           newarray(a,low,mid);
           newarray(a,mid+1,high);
     }
  }
}

void swap(int *x,int *y)
{
    *x=*x+*y;
    *y=*x-*y;
    *x=*x-*y;
}

void main()
{
  int a[10]={1,4,7,8,9,12,13,14,15,16},i;
  printf("Before updating array: ");
  for(i=0;i<10;i++)
    printf("%d ",a[i]);
  newarray(a,0,9);
  printf("\nAfter updating array: ");
  for(i=0;i<10;i++)
    printf("%d ",a[i]);

}
