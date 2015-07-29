#include<stdio.h>
void main()
{
 int a[5]={2,3,6,8,9},b[3]={0,4,7},c[8]={0,0},i=0,j=0,k=0;

 for(k=0;k<=7;k++)
 {
   if(i<5 && j<3 )
   {
    if(a[i]<b[j])
         c[k]=a[i++];
    else
         c[k]=b[j++];
   }
   else
   {
     if(i>=5 && j!=3)
        c[k]=b[j++];
     else
        c[k]=a[i++];
   }
 }
 printf("Combined sorted array : ");
 i=0;
 for(i=0;i<8;i++)
    printf("%d ",c[i]);
 printf("\nThe median of all the elements is %d",c[4]);


}
