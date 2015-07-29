#include<stdio.h>
#define SIZE 20

int selection(int a[],int low,int high,int key);
int partition(int a[],int low,int high);
void swap(int *x,int *y);

int selection(int a[],int low,int high,int key)
{
  int k=key-1;
  if(low==high)
    return a[low];
  else
  {
     int pivot=partition(a,low,high);
     if(pivot==k)
        return a[pivot];
     else if(pivot>k)
        return selection(a,low,pivot-1,key);
     else
        return selection(a,pivot+1,high,key);
  }
}

int partition(int a[],int low,int high)
{
  int i=0,pivot=low,pivotitem=a[low];

  for(i=low+1;i<=high;i++)
  {
     if(a[i]<pivotitem)
     {
       pivot++;
       swap(&a[i],&a[pivot]);
     }
  }
  swap(&a[low],&a[pivot]);
  return pivot;
}

void swap(int *x,int *y)
{
  *x=*x+*y;
  *y=*x-*y;
  *x=*x-*y;
}

void main()
{
    int i=0,a[SIZE]={0,0},count=0,key=0;
    printf("Enter the elements(not more than 10 and enter -1 to exit):\n");
    while(1)
        {
            scanf("%d",&a[i]);
            if(a[i]==-1)
                break;
            else
             {
                count++;
                i++;
             }
        }
    printf("Enter the value of k for kth smallest element = ");
    scanf("%d",&key);
    printf("\nThe kth smallest element is %d",selection(a,0,count-1,key));
}
