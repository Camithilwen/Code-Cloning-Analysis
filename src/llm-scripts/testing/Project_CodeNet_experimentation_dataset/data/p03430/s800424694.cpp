#include <bits/stdc++.h>
using namespace std;

int dp[305][305][305];
string s;

int my(int l,int r,int k)
{
	if (dp[l][r][k]!=0)
	{
		return dp[l][r][k];
	}
	else if (l==r)
	{
		dp[l][r][k]=1;
		return 1;
	}
	else if (l+1==r)
	{
		if (s[l]==s[r]||k>0)
		{
			dp[l][r][k]=2;
			return 2;
		}
		else
		{
			dp[l][r][k]=1;
			return 1;
		}
	}
	int ans=max(my(l+1,r,k),my(l,r-1,k));
	if (s[l]==s[r])
	{
		ans=max(ans,my(l+1,r-1,k)+2);
	}
	else if (k>0)
	{
		ans=max(ans,my(l+1,r-1,k-1)+2);
	}
	dp[l][r][k]=ans;
	return ans;
}

int main(int argc, char const *argv[])
{
	int k;
	cin>>s>>k;
	cout<<my(0,s.size()-1,k)<<endl;
	return 0;
}
