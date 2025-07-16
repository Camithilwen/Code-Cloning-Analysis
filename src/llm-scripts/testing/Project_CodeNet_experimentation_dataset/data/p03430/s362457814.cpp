// Wanna Hack? GL...

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int maxn=310,mod=1e9+7;
const ll inf=1e18;

int dp[2][maxn][maxn];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    string s;cin>>s;
    int k,t=0,n=sz(s);cin>>k;
    for(int r=0;r<n;r++){
	dp[0][r][r]=1;
	for(int l=r-1;l>=0;l--)
	    dp[0][l][r]=max(dp[0][l+1][r],max(dp[0][l][r-1],(s[l]==s[r]?2:0) + dp[0][l+1][r-1]));
    }
    for(int i=1;i<=k;i++){
	memset(dp[t^1],0,sizeof dp[t^1]);
	for(int r=0;r<n;r++){
	    dp[t^1][r][r]=1;
	    for(int l=r-1;l>=0;l--)
		dp[t^1][l][r]=max(dp[t^1][l+1][r],max(dp[t^1][l][r-1],s[l]==s[r]?2+dp[t^1][l+1][r-1]:2+dp[t][l+1][r-1]));
	}
	t^=1;
    }
    return cout<<dp[t][0][n-1]<<endl,0;
}
