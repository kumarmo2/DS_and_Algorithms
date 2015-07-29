#include<stdio.h>
#include<time.h>
#define MAX 10000
void Quicksort(int a[],int p,int r);
int Partition (int a[],int p,int r);
int RandomizedPartition (int a[],int p,int r);
void swap(int *first,int *second);
int median (int a[],int p,int r);

void main()
{
    srand(time(NULL));
    int a[MAX];
    int i=0;
    for(i=0;i<MAX;i++)
        a[i]=rand();

    printf("Before Sorting: ");
    for(i=0;i<MAX;i++)
        printf("%d\n",a[i]);
   printf ("\nStarting...... ");
   clock_t first=clock(),second;

   Quicksort(a,0,MAX-1);
   second=clock();

    printf("\nAfter Sorting: \n");
    for(i=0;i<MAX;i++)
        printf("%d\n",a[i]);
    float t;
    t=(float)(second-first)/CLOCKS_PER_SEC;
    printf("\nTime consumed for quicksort is %f seconds ",t);
}

void Quicksort(int a[],int p,int r)
{
   while(p<r)
   {
       int q=RandomizedPartition(a,p,r);
       Quicksort(a,p,q-1);

       p=q+1;
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
    int j,temp=0;
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
