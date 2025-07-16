#include <bits/stdc++.h>
using namespace std;

const long long mod=1000000007;

long long dp[2][2000000],cnt[2000000]={},z=0LL;

long long modpow(int a,int b)
{
	if (b==0)
	{
		return 1LL;
	}
	long long ans=modpow(a,b/2);
	ans*=ans;
	ans%=mod;
	if (b%2==1)
	{
		ans*=a;
		ans%=mod;
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int a[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	int s[n];
	s[0]=a[0];
	for (int i = 1; i < n; ++i)
	{
		s[i]=s[i-1]^a[i];
	}
	for (int i = 0; i < 2000000; ++i)
	{
		dp[0][i]=1LL;
	}
	for (int i = 0; i < n; ++i)
	{
		if (s[i]==0)
		{
			++z;
		}
		dp[0][s[i]]+=dp[1][s[i]]*(z-cnt[s[i]])%mod;
		dp[0][s[i]]%=mod;
		dp[1][s[i]]+=dp[0][s[i]];
		dp[1][s[i]]%=mod;
		cnt[s[i]]=z;
	}
	if (s[n-1]!=0)
	{
		cout<<dp[0][s[n-1]]<<endl;
	}
	else
	{
		long long ans=modpow(2,z-1);
		for (int i = 1; i < 2000000; ++i)
		{
			ans+=dp[1][i];
			ans%=mod;
		}
		cout<<ans<<endl;
	}
	return 0;
}
