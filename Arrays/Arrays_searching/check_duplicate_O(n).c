#include<stdio.h>
void main()
{
    int a[10];
    int i=0;
    printf("Enter the array elements(value should not be more than 5): ");
    for(i=0;i<5;i++)
        scanf("%d ",&a[i]);
    int b[10];
    for(i=0;i<10;i++)
    {
      if(b[a[i]]<0)
      {
        printf("Duplicates exist %d !!!",a[i]);
        return;
      }
      else
        b[a[i]]=-a[i];
    }


}
