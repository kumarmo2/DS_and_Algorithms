#include<stdio.h>

void Quicksort(int a[],int p,int r);
int Partition (int a[],int p,int r);
void check_duplicate(int a[],int n);


void main()
{

    int a[10];
    int i=0;
    printf("Enter the array elements : ");
    for(i=0;i<10;i++)
        scanf("%d ",&a[i]);

    printf("Before Sorting: ");
    for(i=0;i<10;i++)
        printf("%d\n",a[i]);
   printf ("\nStarting...... ");


   Quicksort(a,0,9);

    printf("\nAfter Sorting: \n");
    for(i=0;i<10;i++)
        printf("%d\n",a[i]);

    check_duplicate(a,10);
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

void check_duplicate(int a[],int n)
{
    int i=0;
    for(i=0;i<n;i++)
    {
        if(a[i]==a[i+1])
        {
             printf("Duplicates exists %d",a[i]);
             return;
        }
    }
    printf("Duplicates doesnot exist !!!!");
}

