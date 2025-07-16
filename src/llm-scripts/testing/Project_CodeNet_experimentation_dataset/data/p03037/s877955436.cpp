#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
struct node{
	int a;
	int b;
}x[100005];

int main()
{
  int n,m;
  scanf("%d%d",&n,&m);
  for(int i=0;i<m;i++)
  {
      scanf("%d%d",&x[i].a,&x[i].b);
  }
  int start=x[0].a;
  int end=x[0].b;
  for(int i=1;i<m;i++)
  {
  	start=max(x[i].a,start);
  	end=min(x[i].b,end);
  }	
  int sum=end-start+1;
  if(sum<0)
  sum=0;
  printf("%d\n",sum);
  return 0; 
}
 