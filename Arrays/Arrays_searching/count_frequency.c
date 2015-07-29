#include<stdio.h>

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

void Count(int a[],int n)
{
 int i=0;
 printf("\nThe frequency of the elements are:\n");
 for(i=0;i<10;i++)
 {
   int count=1;
   while(a[i]==a[i+1])
   {
     count++;
     i++;
   }
   printf("%d occurs %d times\n",a[i],count);

 }
}

void main()
{
  int a[10]={5,3,5,11,3,4,11,3,4,11},i=0;
  printf("The array is: ");
  for(i=0;i<10;i++)
    printf("%d ",a[i]);
  Quicksort(a,0,9);
  Count(a,10);
}
