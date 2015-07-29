 #include<stdio.h>
#define MAX 1000
#include<time.h>
#include<limits.h>
void Merge(int a[],int p,int q,int r);
void Merge_Sort(int a[],int p,int r);

void main ()
{
    srand(time(NULL));
    int a[MAX];
    int i=0;
    for(i=0;i<MAX;i++)
        a[i]=rand();


    printf ("Before Sorting: ");
    for(i=0;i<MAX;i++)
        printf("%d\n",a[i]);
   printf ("\nStarting...... ");
   clock_t first=clock(),second;
    Merge_Sort(a,0,MAX-1);
   second=clock();

    printf("\nAfter Sorting: ");
    for(i=0;i<MAX;i++)
        printf("%d\n",a[i]);
    float t;
    t=(float)(second-first)/CLOCKS_PER_SEC;
    printf("\nTime consumed for merge sort is %f seconds ",t);


}

void Merge(int a[],int p,int q,int r)
{
    int i,j,k=0;
    int n1=q-p+1;
    int n2=r-q;
    int L[MAX]={0,0},R[MAX]={0,0};
    for (i=0;i<n1;i++)
        L[i]=a[p+i];
    for (j=0;j<n2;j++)
        R[j]=a[q+j+1];
    L[n1]=INT_MAX;
    R[n2]=INT_MAX;
    i=j=0;
    for(k=p;k<=r;k++)
    {
        if(L[i]<=R[j])
        {
          a[k]=L[i];
          i++;
        }
        else
        {
          a[k]=R[j];
          j++;
        }
    }

}

void Merge_Sort(int a[],int p,int r)
{

    if(p<r)
    {
        int q=((p+r)/2);
        Merge_Sort(a,p,q);
        Merge_Sort(a,q+1,r);
        Merge(a,p,q,r);
    }
}
