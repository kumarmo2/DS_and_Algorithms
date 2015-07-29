#include<stdio.h>
#include<math.h>

#include<stdio.h>
#include<time.h>
#define MAX 10
void Quicksort(int a[],int p,int r);
int Partition (int a[],int p,int r);
int RandomizedPartition (int a[],int p,int r);
int median(int a[],int p,int r);
void swap(int *first,int *second);


void Quicksort(int a[],int p,int r)
{
   if(p<r)
   {
       int q=RandomizedPartition(a,p,r);
       Quicksort(a,p,q-1);
       Quicksort(a,q+1,r);
   }
}
int RandomizedPartition(int a[],int p,int r)
{
    int i=median(a,p,r);
    swap(a+r,a+i);

   return Partition(a,p,r);
}
int median (int a[],int p,int r)
{
    int q=(p+r)/2;
    if(a[p]>a[q])
        swap(a+p,a+q);
    if(a[p]>a[r])
        swap(a+p,a+r);
    if(a[q]>a[r])
        swap(a+q,a+r);
    return q;

}

void swap(int *first,int *second)
{
    int temp=*first;
    *first=*second;
    *second=temp;
}

int Partition(int a[],int p,int r)
{
    int x=a[r];
    int j;
    int i=p-1;
    for(j=p;j<=r-1;j++)
    {
        if(a[j]<=x)
        {
            i=i+1;
            swap(a+j,a+i);

        }
    }

    swap(a+r,a+i+1);

    return i+1;

}


void main()
{
 int i,j,k,a[6]={6,2,3,8,9,10},b[6]={0,0};

 for(i=0;i<6;i++)
   {
    b[i]=a[i]*a[i];
   }
Quicksort(a,0,5);
Quicksort(b,0,5);
for(k=5;k>1;k--)
{
    i=0;
    for(j=k-1;j>=i;)
    {
        if(b[j]+b[i]==b[k])
        {
            printf("%d %d %d",a[i],a[j],a[k]);
            return;
        }
        else if(b[j]+b[i]>b[k])
           j--;
        else
            i++;
    }
}
printf("No such pair found !!!!");
}
