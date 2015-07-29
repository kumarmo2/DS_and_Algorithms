#include<stdio.h>
#include<limits.h>
#define SIZE 20
int ksmallest(int a[],int n,int key);

int ksmallest(int a[],int n,int key)
{
  int i=0,j=0,index=-1;

  for(i=0;i<key;i++)
  {
    for(j=n-1;j>=i+1;j--)
    {
      if(a[i]<a[j]?1:0)
        index=i;
      else
        index=j;
    }
    if(i<key-1)
        a[index]=INT_MAX;
  }
 return a[index];
}

void main()
{
    int i=0,a[SIZE]={0,0},count=0,key=0;
    printf("%d",x);
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
    printf("Enter the value of k for kth smallest element = ");
    scanf("%d",&key);
    printf("\nThe kth smallest element is %d",ksmallest(a,count,key));
}
