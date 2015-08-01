#include<stdio.h>
void *findingspans(int a[],int n);

void *findingspans(int a[],int n)
{
    int s[20]={0,0};
    int i=0,j;
    for(i=0;i<n;i++)
    {
        j=1;
        while(j<=i && a[i]>=a[i-j])
        {
            j++;
        }
        s[i]=j;
    }
    i=0;
    while(i<n)
        printf("%d ",s[i++]);
}

void main()
{
    printf("Enter array elements(Press -1 to stop: ");
    int a[20]={0,0},data,j=0;
    while(1)
    {
        scanf("%d",&data);
        if(data==-1)
            break;
        else
            a[j++]=data;
    }
    int n=j;
    printf("\nThe max of j-i subjected to the constraint a[j]<=a[i] :");
    findingspans(a,n);

}
