#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=1e9+7;
string sa;
ll d,dp[10010][110];
ll dfs_dp(int pos,ll sta,bool lim)
{
	if(pos==sa.size())
		return sta%d==0;
	if(!lim && dp[pos][sta]!=-1)
		return dp[pos][sta];
	ll up=lim?(sa[pos]-'0'):9,res=0;
	for(int i=0;i<=up;i++)
		res=(res+dfs_dp(pos+1,(sta+i)%d,lim&(i==up)))%mod;
	if(!lim)
		dp[pos][sta]=res;
	return res;
}
ll work()
{
	return dfs_dp(0,0,1);
}
int main()
{
	memset(dp,-1,sizeof(dp));
	cin>>sa>>d;
	cout<<(work()+mod-1)%mod<<endl;
	return 0;
}