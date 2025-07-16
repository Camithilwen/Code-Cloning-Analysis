#include<bits/stdc++.h>
#define MOD (long long)(1e9+7)
using namespace std;
long long n,a[20][20],dp[1<<17],sum[1<<17];
int main()
{
	cin >> n;
	for(int i=0; i<n; i++) for(int j=0; j<n; j++) cin >> a[i][j];
	for(int i=0; i<(1<<n); i++) for(int j=0; j<n; j++) for(int k=j+1; k<n; k++)
		if((i&(1<<j)) && (i&(1<<k))) sum[i]+=a[j][k];
	for(int i=0; i<(1<<n); i++)
	{
		vector<int> pos;
		for(int j=0; j<n; j++) if(i&(1<<j)) pos.push_back(1<<j);
		int m=pos.size();
		for(int j=0; j<(1<<m); j++)
		{
			int c=0;
			for(int k=0; k<m; k++) if(j&(1<<k)) c+=pos[k];
			dp[i]=max(dp[i],dp[i-c]+sum[c]);
		}
	}
	long long ans=0;
	for(int i=0; i<(1<<n); i++) ans=max(ans,dp[i]);
	cout << ans;
	return 0;
}