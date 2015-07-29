#include<stdio.h>
void DutchNationalFlag(int a[],int n);
void swap(int *x,int *y);

void DutchNationalFlag(int a[],int n)
{
    int left=0,right=n-1;
    while(left<right)
    {
        while(a[left]%2==0 && left<right)
            left++;
        while(a[right]%2==1 & left<right)
            right--;
        if(left<right)
        {
            swap(&a[left],&a[right]);
            left++;
            right--;
        }
    }
}

void swap(int *x,int *y)
{
    *x=*x+*y;
    *y=*x-*y;
    *x=*x-*y;
}

void main()
{
    int a[10]={1,2,3,4,5,6,7,8,9,10},i=0;
    printf("Before separation: ");
    for(i=0;i<10;i++)
        printf("%d ",a[i]);
    DutchNationalFlag(a,10);
    printf("\nAfter separation: ");
    for(i=0;i<10;i++)
        printf("%d ",a[i]);
}
