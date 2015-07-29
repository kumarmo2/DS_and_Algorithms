#include<stdio.h>
#include<math.h>
#include<limits.h>

void main()
{
    int a[6]={1,60,-10,70,-80,85};
    int i,j,min_sum=INT_MAX,min_i,min_j,sum;
    for(i=0;i<6;i++)
    {
        for(j=i+1;j<6;j++)
        {
          sum=a[i]+a[j];
          if(abs(sum)<abs(min_sum))
          {
             min_sum=sum;
             min_i=i;
             min_j=j;
          }
        }
    }
    printf("Pair whose sum is closest to zero are %d and %d and the sum is %d",a[min_i],a[min_j],min_sum);

}
