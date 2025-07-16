#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
int prime[2020],np;
bool vis[10101];
void findprime()
{
	memset(vis,0,sizeof(vis));
	np=0;
	for(int i=2;i<=10000;i++)
	{
		if(!vis[i])
			prime[++np]=i;
		for(int j=1;j<=np&&i*prime[j]<=10000;j++)
		{
			vis[i*prime[j]]=true;
			if(i%prime[j]==0)
				break;
		}
	}
}
long long ans[505][505];
long long gcd(long long x,long long y)
{
	if(y==0)
		return x;
	return gcd(y,x%y);
}
long long lcm(long long x,long long y)
{
	return x/gcd(x,y)*y;
}
int hx[4]={-1,1,0,0};
int hy[4]={0,0,-1,1};
int main()
{
	int n;
	findprime();
	scanf("%d",&n);
	if(n==2)
	{
		printf("4 7\n23 10");
		return 0;
	}
	for(int i=0;i<=n+1;i++)
		for(int j=0;j<=n+1;j++)
			ans[i][j]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if((i+j)%2==0)
				ans[i][j]=prime[(i+j)/2]*prime[(n-j+1+i)/2+n];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if((i+j)%2==1)
			{
				for(int k=0;k<4;k++)
					ans[i][j]=lcm(ans[i][j],ans[i+hx[k]][j+hy[k]]);
				ans[i][j]++;
			}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			printf("%lld ",ans[i][j]);
		printf("\n");
	}
	return 0;
}