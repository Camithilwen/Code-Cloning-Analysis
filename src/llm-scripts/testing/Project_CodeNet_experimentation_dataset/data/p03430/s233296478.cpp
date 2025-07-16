#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
 
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef unsigned long long ull;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int dp[311][311][311];
string s;

int solve(int l, int r, int k)
{
	if(k<0) return -int(1e9);
	if(l>r) return 0;
	if(dp[l][r][k]>=0) return dp[l][r][k];
	if(l==r) return 1;
	int ans = max(solve(l,r-1,k),solve(l+1,r,k));
	ans=max(ans,solve(l+1,r-1,k-(s[l]!=s[r]))+2);
	return (dp[l][r][k]=ans);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>s; int k; cin>>k;
	memset(dp,-1,sizeof(dp));
	cout<<solve(0,int(s.length())-1,k)<<'\n';
}
