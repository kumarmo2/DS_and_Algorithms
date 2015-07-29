#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int*,int*);
void bubbleSort(int arr[],int n);

main()
{
	int arr[10];
	srand(time(NULL));
	int i;
	for(i=0;i<10;i++)
       arr[i]=10-i ;
	printf("The array is : \n");
	int n=sizeof(arr)/sizeof(arr[0]);
    for(i=0;i<10;i++)
	   printf("%d\n",arr[i]);
	clock_t first=clock(),second;
	printf("Starting...\n");
	bubbleSort(arr,n);
	second = clock();
	printf("\n%f",(float)(second - first) / CLOCKS_PER_SEC );
	printf("\nAfer Sorting...\n");
	for(i=0;i<10;i++)
	   printf("%d\n",arr[i]);
}

void bubbleSort(int arr[], int n)
{
   int i, j,flag;
   for (i = 0; i < n-1; i++)
   {
       flag=0;  // to check whether the list is already sorted or not
       for (j = 0; j < n-i-1; j++) //Last i elements are already in place
       {
           if (arr[j] > arr[j+1])
           {
              swap(&arr[j], &arr[j+1]);
              flag=1;
           }
       }
       if(flag==0)
         break;      // the list is already sorted leaves the remaining passes
   }
}

void swap(int *first,int *second)
{
	int temp = *first;
	*first = *second;
	*second = temp;
}
