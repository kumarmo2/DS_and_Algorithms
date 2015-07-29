#include<stdio.h>
#include<limits.h>

#define MAX 20
int getmax(int a[],int n);
void countsort(int a[],int n,int exp);
void radixsort(int a[],int n);

int getmax(int a[],int n)
{
    int i,max=INT_MIN;
    for(i=0;i<n;i++)
    {
        if(a[i]>max)
            max=a[i];
    }
    return max;
}

void radixsort(int a[],int n)
{
    int m=getmax(a,n);
    int exp;
    for(exp=1;m/exp>0;exp*=10)
        countsort(a,n,exp);
}

void countsort(int a[],int n,int exp)
{
    int b[10]={0,0};
    int c[10]={0,0};
    int i;
    for(i=0;i<10;i++)
        c[(a[i]/exp)%10]++;
    for(i=1;i<10;i++)
        c[i]=c[i] + c[i-1];

    for(i=n-1;i>=0;i--)
    {
        b[c[((a[i]/exp)%10)]-1]=a[i];
        c[(a[i]/exp)%10]--;
    }

    for(i=0;i<n;i++)
        a[i]=b[i];
}

void main()
{
int a[10]={32,87,87,98,23,12,76,823,90,125};
int n=sizeof(a)/sizeof(a[0]);
int i;
printf("The array before sorting is : \n");
for(i=0;i<n;i++)
    printf("%d ",a[i]);
radixsort(a,n);
printf("\nThe array after sorting is : \n");
for(i=0;i<n;i++)
    printf("%d ",a[i]);
}
