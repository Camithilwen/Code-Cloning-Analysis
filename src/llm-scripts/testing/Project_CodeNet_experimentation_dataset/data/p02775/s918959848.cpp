#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define N 1000005
using namespace std;
typedef long long LL;
char s[N];
int dp[N][2];
int main()
{
	scanf("%s",s+1);
	dp[0][1]=1;
	for(int i=1;s[i];i++)
	{
		int d=s[i]-'0';
		dp[i][0]=min(dp[i-1][0]+d,dp[i-1][1]+10-d);
		dp[i][1]=min(dp[i-1][0]+d+1,dp[i-1][1]+9-d);
		if(d==9)dp[i][1]=dp[i-1][1];
	}
	printf("%d\n",dp[strlen(s+1)][0]);
	return 0;
}
