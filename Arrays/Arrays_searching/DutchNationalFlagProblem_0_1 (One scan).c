#include<stdio.h>
void DutchNationalFlag(int a[],int n);
void swap(int *x,int *y);

void DutchNationalFlag(int a[],int n)
{
    int left=0,right=n-1;
    while(left<right)
    {
        while(a[left]==0 && left<right)
            left++;
        while(a[right]==1 & left<right)
            right--;
        if(left<right)
        {
            a[left]=0;
            a[right]=1;
            left++;
            right--;
        }
    }
}



void main()
{
    int a[10]={0,1,0,0,1,1,1,1,0,1},i=0;
    printf("Before separation: ");
    for(i=0;i<10;i++)
        printf("%d ",a[i]);
    DutchNationalFlag(a,10);
    printf("\nAfter separation: ");
    for(i=0;i<10;i++)
        printf("%d ",a[i]);
}
