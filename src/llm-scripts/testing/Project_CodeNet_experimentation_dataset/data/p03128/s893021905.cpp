#pragma GCC optimize ("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse4")
#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int ll
#define sz(x) (int)(x).size();
#define all(x) x.begin(), x.end()
#define trav(i,a) for(auto &i:a) 
inline int in(){int x;scanf("%lld",&x);return x;}
int h[10]={0,2,5,5,4,5,6,3,7,6};
int32_t main()
{
	int n=in();int m=in();
	vector<char> a(m);
	trav(i,a)cin>>i;
	vector<string> dp(n+10);
	//dp[i] best answer with i sticks
	//making only given digits from a(m)
	dp[0]="";
	for(int i=0;i<m;i++)
	{
		dp[h[a[i]-'0']]=max(dp[h[a[i]-'0']],(string)""+a[i]);
	}
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(dp[i]=="")continue;
			if((i+h[a[j]-'0'])>n)continue;
			if(dp[i+h[a[j]-'0']].size()>dp[i].size()+1)continue;
			if(dp[i+h[a[j]-'0']].size()<dp[i].size()+1)
			{
				dp[i+h[a[j]-'0']]=dp[i]+a[j];
			}
			else
			dp[i+h[a[j]-'0']]=max(dp[i]+a[j],dp[i+h[a[j]-'0']]);
			
		}
	}
	cout<<dp[n];
	
	
}