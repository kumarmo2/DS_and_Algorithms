#include<stdio.h>
#include<string.h>
#define d 256

int searchstring(char *txt,char *pat,int q);

int searchstring(char *txt,char *pat,int q)
{
 int n=strlen(txt);
 int m=strlen(pat);
 int h=1,i=0,j=0,t=0,p=0;
 for(i=0;i<m-1;i++)
     h=(h*d)%q;

  for(i=0;i<m;i++)
  {
   t=(d*t+txt[i])%q;
   p=(d*p+pat[i])%q;;
  }

  for(i=0;i<=n-m;i++)
  {
    if(t==p)
    {
      for(j=0;j<m;j++)
      {
        if(txt[i+j]!=pat[j])
           break;
      }
      if(j==m)
        return i;
    }
    if(i<n-m)
    {
      t=(d*(t-h*txt[i])+txt[i+m])%q;
      if(t<0)
        t=t+q;
    }
  }
  return -1;
}

void main()
{
  printf("Enter a string in which you want to search = ");
  char txt[100];
  gets(txt);
  char pat[100];
  printf("\nEnter a string you want to search = ");
  gets(pat);
  int q=101;
  int index=searchstring(txt,pat,q);
  if(index!=-1)
    printf("\nString found at index %d",index);
  else
    printf("\nString not found !!!");
}
