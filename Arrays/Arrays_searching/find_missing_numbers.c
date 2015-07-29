#include<stdio.h>
int find_missing_number(int a[],int n);
void main()
{
    int a[9]={1,2,3,5,6,4,7,10,9}; // range of numbers are 1 to 10 and total numbers are 10
    printf("The missing number is %d",find_missing_number(a,10));
}

int find_missing_number(int a[],int n)
{
    int i=0,x=a[0],y=1;
    for(i=0;i<n-1;i++)
            x^=a[i];
    for(i=1;i<=n;i++)
            y^=i;

    return x^y;
}
