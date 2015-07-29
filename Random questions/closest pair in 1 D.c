#include<stdio.h>
#include<limits.h>
void Quicksort(int a[],int p,int r);
int Partition (int a[],int p,int r);
void closestpair(int a[],int n);

void closestpair(int a[],int n)
{
  int least_diff=INT_MAX;
  int i=0,j=0,d1,d2,p1,p2;

  for(i=0,j=n-1;j-i>2;i++,j--)
  {
    d1=a[i+1]-a[i];
    if(d1<least_diff)
    {
        least_diff=d1;
        p1=i;
        p2=i+1;
    }
    d2=a[j]-a[j-1];
    if(d2<least_diff)
    {
        least_diff=d2;
        p1=j-1;
        p2=j;
    }

  }
  printf("\nThe closest pair is(%d,%d) and the corresponding least difference is %d",a[p1],a[p2],least_diff);
}

void Quicksort(int a[],int p,int r)
{
   if(p<r)
   {
       int q=Partition(a,p,r);
       Quicksort(a,p,q-1);
       Quicksort(a,q+1,r);
   }
}

int Partition(int a[],int p,int r)
{
    int x=a[r];
    int j,temp=0;
    int i=p-1;
    for(j=p;j<=r-1;j++)
    {
        if(a[j]<=x)
        {
            i=i+1;
            temp=a[j];
            a[j]=a[i];
            a[i]=temp;
        }
    }
    temp=a[r];
    a[r]=a[i+1];
    a[i+1]=temp;
    return i+1;
}

void main()
{
  printf("Enter positions (max 10) : ");
  int a[10]={0,0},i;
  for(i=0;i<10;i++)
    scanf("%d",&a[i]);
  Quicksort(a,0,9);
  closestpair(a,10);
}
