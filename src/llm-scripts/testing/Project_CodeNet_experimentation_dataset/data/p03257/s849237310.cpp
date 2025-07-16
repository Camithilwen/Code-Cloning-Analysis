#include<iostream>
#include<cstdio>
using namespace std;
int n,sz;
int a[10101],d[10101];
long long an[1010][1010];
void init(int N)
{
	for(int i=2;i<=N;i++)
	{
		if(!d[i])a[++sz]=i;
		for(int j=1;j<=sz&&a[j]*i<=N;j++)
		{
			d[i*a[j]]=1;
			if(i%a[j]==0) break;
		}
	}
}
long long gcd(long long x,long long y){ return y?gcd(y,x%y):x;}
long long lcm(long long x,long long y)
{
	if(!x||!y) return x+y;
	return x/gcd(x,y)*y;
}
int main()
{
	scanf("%d",&n);
	init(10000);
	if(n==2)
	{
		an[1][1]=4;an[1][2]=7;an[2][1]=23;an[2][2]=10;
	}
	else
	{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			if((i+j)&1)
				an[i][j]=1LL*a[(i+j)/2]*a[(i-j+n)/2+1+n];
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			if(((i+j)&1)^1)
				an[i][j]=lcm(lcm(an[i-1][j],an[i+1][j]),lcm(an[i][j-1],an[i][j+1]))+1;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		printf("%lld ",an[i][j]);
		puts("");
	}
	return 0;
}