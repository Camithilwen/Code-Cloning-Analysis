#include<bits/stdc++.h>
using namespace std;
const int N=305;
int a,b,c,tmp;
double n,dp[N][N][N];
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>tmp;
		if(tmp==1)a++;
		else if(tmp==2)b++;
		else c++;
	}
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			for(int k=0;k<=n;k++)
			{
				if(!i&&!j&&!k)continue;
				if(i)dp[i][j][k]+=dp[i-1][j+1][k]*i;
				if(j)dp[i][j][k]+=dp[i][j-1][k+1]*j;
				if(k)dp[i][j][k]+=dp[i][j][k-1]*k;
				dp[i][j][k]=dp[i][j][k]/(i+j+k);
				dp[i][j][k]+=n/(i+j+k);
			}
		}
	}
	cout<<fixed<<setprecision(12)<<dp[c][b][a]<<endl;
	return 0;
}