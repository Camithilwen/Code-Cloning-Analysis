#include<bits/stdc++.h>
using namespace std;
const int N=1000005,E=262144;
const int M=998244353;
int n,m,i,j,s,a[N],dp[6005][12005];
long long dfs(int i,int j)
{
	if(i<0)
		return 0;
	if(i==0)
		if(j>=0&&j%3==0)
			return 1;
		else
			return 0;
	if(dp[i][j+6000]!=-1)
		return dp[i][j+6000];
	long long s=dfs(i-1,j+1);
	s+=dfs(i-2,j-1)*(i-1);
	s+=dfs(i-3,j)*(i-1)*(i-2);
	return dp[i][j+6000]=s%m;
}
int main()
{
	scanf("%d %d",&n,&m);
	memset(dp,-1,sizeof(dp));
	cout<<dfs(n*3,0);
}
