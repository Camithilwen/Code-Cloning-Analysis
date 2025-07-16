#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<stdio.h>
#include<locale.h>
#include<set>
#include<stack>
#include<queue>
#include<math.h>
using namespace std;
typedef long long int ll;
 
int main()
{
 int N,M;
 scanf("%d %d",&N,&M);
 int ans=1;
 for(int i=1;i<=min(100000,M);i++)
 {
	if(M%i==0)
	{
		//約数はiとM/i
		if(i>=N){ans=max(ans,M/i);}
		if((M/i)>=N){ans=max(ans,i);}
	}
 }
 printf("%d",ans);
} 