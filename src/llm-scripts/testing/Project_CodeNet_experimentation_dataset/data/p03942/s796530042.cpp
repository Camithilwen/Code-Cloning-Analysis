#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int n,x[1000010],p;
char s[1000010],t[1000010];
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j,k,l;
	scanf("%d%s%s",&n,&s,&t);
	for(i=n-1,j=n,k=0,l=0;i>=0;i--)
	  {
	   if(j>i && t[i]!=s[i])
	     j=i;
	   if(j<=i && t[i]!=s[j])
	     {
	      for(;j>=0 && t[i]!=s[j];j--);
	      if(j<0)
	        {
	         printf("-1\n");
	         return 0;
	        }
	      k++;
	      l++;
	      x[j+l]++;
	      p=max(p,k);
	     }
	   k-=x[i+l];
	   x[i+l]=0;
      }
    printf("%d\n",p);
	return 0;
}
