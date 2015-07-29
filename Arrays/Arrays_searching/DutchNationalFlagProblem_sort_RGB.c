#include<stdio.h>
void sortRGB(char a[],int n);
void swap(char *x,char *y);

void sortRGB(char a[],int n)
{
  int low=0,mid=0,high=n-2;

  while(mid<=high)
  {
    switch (a[mid])
    {
      case 'R':
               swap(&a[low],&a[mid]);
               mid++;
               low++;
               break;
      case 'G':
               mid++;
               break;
      case 'B':
               swap(&a[mid],&a[high]);
               high--;
               break;
    }
  }
}

void swap(char *x,char *y)
{
  *x=*x+*y;
  *y=*x-*y;
  *x=*x-*y;
}

void main()
{
    char a[7]={'B','R','G','R','G','B','\0'};
    printf("Before sorting: ");
    printf("%s",a);
    sortRGB(a,7);
    printf("\nAfter sorting: ");
    printf("%s",a);
}
