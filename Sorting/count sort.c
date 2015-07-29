#include<stdio.h>
void countsort(int a[],int b[],int c[],int n,int k);

void countsort(int a[],int b[],int c[],int n,int k)
{
  int i;

  for(i=0;i<n;i++)
    c[a[i]]=c[a[i]]+1;
  for(i=1;i<=k;i++)
    c[i]=c[i]+c[i-1];
 for(i=0;i<=k;i++)
    printf("%d ",c[i]);

  for(i=n-1;i>=0;i--)
  {
    b[c[a[i]]-1]=a[i];
    c[a[i]]=c[a[i]]-1;
  }
}

void main()
{
  printf("The array before sorting is:");
  int a[10]={1,4,7,2,1,4,7,6,2,1},i,k;
  for(i=0;i<10;i++)
    printf("%d ",a[i]);
  printf("\nEnter the max value of the element in the array = ");
  scanf("%d",&k);
  int c[8]={0,0},b[10]={0,0};
  countsort(a,b,c,10,7);
  printf("\nThe array before sorting is:");
  for(i=0;i<10;i++)
    printf("%d ",b[i]);
}
