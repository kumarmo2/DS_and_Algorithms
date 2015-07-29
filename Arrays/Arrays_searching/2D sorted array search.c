#include<stdio.h>
int search(int a[5][5],int row,int column,int data);

int search(int a[][5],int row,int column,int data)
{
 if(row<5 && column<5)
 {
  if(a[row][column]==data)
    return 1;
  else if(a[row][column]>data)
    return search(a,row-1,column,data);
  else
    return search(a,row,column+1,data);
 }
 else
   return 0;
}

void main()
{
 int a[5][5]={{0,2,3,4,5},
              {1,22,33,44,66},
              {6,32,43,55,77},
              {9,42,53,65,87},
              {10,53,63,75,97}};
 int res=search(a,4,0,55);
 if(res)
   printf("Element exists !!!");
 else

   printf("Element not found !!!");
}
