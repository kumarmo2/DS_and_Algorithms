#include<stdio.h>
#include<time.h>
#define MAX 10000
void Quicksort(int a[],int p,int r);
int Partition (int a[],int p,int r);


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
