#include<stdio.h>
#include<string.h>
#define MAX 100
int F[MAX]={0,0};

void prefix_table(char P[],int m);

void prefix_table(char P[],int m)
{
 int i=1,j=0;
 while(i<m)
 {
   if(P[i]==P[j])
   {
     F[j]=j+1;
     i++;
     j++;
   }
   else if(j>0)
   {
     j=F[j-1];
   }
   else
   {
     F[j]=0;
     i++;
   }
 }
}

int KMP(char T[],int n,char P[],int m)
{
 int i=0,j=0;
 prefix_table(P,m);
 while(i<n)
 {
   if(T[i]==P[j])
   {
     if(j==m-1)
       return (i-j);
     else
     {
       i++;
       j++;
     }
   }
   else if(j>0)
   {
      j=F[j-1];
   }
   else
   {
      i++;
   }
 }
 return -1;
}

void main()
{
  char *txt="Preetom";
  printf("%s",txt);
  char *pat="tom";
  printf("\n%s",pat);
  int n=strlen(txt);
  int m=strlen(pat);
  if (KMP(txt,n,pat,m)!=-1)
      printf("\nPattern found at index %d",KMP(txt,n,pat,m));
  else
      printf("\nPattern not found !!!");
}
