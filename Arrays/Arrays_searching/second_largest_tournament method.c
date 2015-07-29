#include<stdio.h>
#include<limits.h>
#define SIZE 20
int secondlargest(int a[],int n);

int secondlargest(int a[],int n)
{
    int i=0,j=0,temp[SIZE]={0,0};
    if(n==2)
        return a[0]<a[1]?a[0]:a[1];
    else
        {
          for(i=0,j=0;i<n && j<n/2;i=i+2,j++)
          {
            temp[j]=a[i]>a[i+1]?a[i]:a[i+1];
          }
          return secondlargest(temp,n/2);
        }
}

void main()
{
    int i=0,a[SIZE]={0,0},count=0;
    printf("Enter the elements(not more than 10 and enter -1 to exit):\n");
    while(1)
        {
            scanf("%d",&a[i]);
            if(a[i]==-1)
                break;
            else
             {
                count++;
                i++;
             }
        }
    if(count%2==1)
    {
        a[i]=INT_MIN;
        count++;
    }
    printf("The second largest element is %d",secondlargest(a,count));
}

