// A Brute-Force based program for maximum subarray sum problem  O

#include<stdio.h>
void main()
{
 int i,j=0;
 int a[]={-20,6,5,-10,-15};
 int n=sizeof(a)/sizeof(a[0]);
 int max=a[0];
 int temp_max=0;
 int max_left=0;
 int max_right=0;
printf("The given array is: [ ");
for(i=0;i<n;i++)
     printf("%d, ",a[i]);
 printf("\b\b ]");
 for(i=0;i<n;i++)
 {
     temp_max=0;
     for (j=i;j<n;j++)
     {
         temp_max=temp_max+a[j];

         if(temp_max>max)
         {
           max_left=i;
           max_right=j;
           max=temp_max;
         }
     }

 }
 printf("\nThe max sub-array is: [ ");
  for(i=max_left;i<=max_right;i++)
     printf("%d, ",a[i]);
 printf("\b\b ]");

 printf("\nThe max subarray SUM is :%d",max);

}
