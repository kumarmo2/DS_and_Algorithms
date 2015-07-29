// A Divide and Conquer based program for maximum subarray sum problem
#include <stdio.h>
#include <limits.h>
int max1(int a, int b);
int max2(int a, int b, int c);
int maxSubArraySum(int arr[], int l, int h);
int maxCrossingSum(int arr[], int l, int m, int h);


/*Driver program to test maxSubArraySum*/
int main()
{
   int arr[] = {2, 3, -4, 5, 7};
   int n = sizeof(arr)/sizeof(arr[0]);
   int max_sum = maxSubArraySum(arr, 0, n-1);
   printf("Maximum contiguous sum is %d\n", max_sum);

   return 0;
}
// A utility funtion to find maximum of two integers
int max1(int a, int b)
 {
     return (a > b)? a : b;
 }

// A utility funtion to find maximum of three integers
int max2(int a, int b, int c)
 {
     return max1(max1(a, b), c);
 }

// Find the maximum possible sum in arr[] auch that arr[m] is part of it
int maxCrossingSum(int arr[], int l, int m, int h)
{
    // Include elements on left of mid.
    int sum=0,i = 0;
    int left_sum = INT_MIN;
    for (i = m; i >= l; i--)
    {
        sum = sum + arr[i];
        if (sum > left_sum)
          left_sum = sum;
    }

    // Include elements on right of mid
    sum = 0;
    int right_sum = INT_MIN;
    for (i = m+1; i <= h; i++)
    {
        sum = sum + arr[i];
        if (sum > right_sum)
          right_sum = sum;
    }

    // Return sum of elements on left and right of mid
    return left_sum + right_sum;
}

// Returns sum of maxium sum subarray in aa[l..h]
int maxSubArraySum(int arr[], int l, int h)
{
   // Base Case: Only one element
   if (l == h)
     return arr[l];

   // Find middle point

   else
   {
   int m = (l + h)/2;

   /* Return maximum of following three possible cases
      a) Maximum subarray sum in left half
      b) Maximum subarray sum in right half
      c) Maximum subarray sum such that the subarray crosses the midpoint */
      int left_sum=maxSubArraySum(arr, l, m);
      int right_sum=maxSubArraySum(arr, m+1, h);
      int cross_sum=maxCrossingSum(arr, l, m, h);
      return max2(left_sum,right_sum,cross_sum);
   }
}


