#include<stdio.h>
void selectionsort(int a[],int n);

void selectionsort(int a[],int n)
{
  int i,j;

  for(i=0;i<n-1;i++)
  {
    for(j=i+1;j<n;j++)
    {
       if(a[j]<a[i])
       {
         int temp=a[i];
         a[i]=a[j];
         a[j]=temp;
       }
    }
  }
}

void main()
{
    printf("The array before sorting is :");
    int a[20]={0,0};
    int i;
    for(i=0;i<10;i++)
         a[i]=10-i;
    for(i=0;i<10;i++)
        printf("%d ",a[i]);
    selectionsort(a,10);
    printf("\nThe array after sorting is :");
    for(i=0;i<10;i++)
        printf("%d ",a[i]);
}
