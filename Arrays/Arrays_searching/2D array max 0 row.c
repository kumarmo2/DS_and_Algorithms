#include<stdio.h>
void findmaxrow(int a[5][5],int i,int j);

void findmaxrow(int a[][5],int i,int j)
{
    int count=0;
    if(i<5 && j>=0)
    {
        if(a[i][j]==1)
            findmaxrow(a,i+1,j);
        else
        {
            while(j>=0)
            {
                if(a[i][j]==0)
                    count++;
                j--;
            }
            printf("Row=%d has maximum 0's that is %d",i,count);
            return;
        }
    }
    else
        printf("All the rows have same number of 0's ");
}

void main()
{
    int a[][5]={{1,0,1,0,1},
                 {1,0,1,0,1},
                 {0,1,0,1,0},
                 {1,0,1,0,1},
                 {1,0,1,0,1}};
   findmaxrow(a,0,4);

}
