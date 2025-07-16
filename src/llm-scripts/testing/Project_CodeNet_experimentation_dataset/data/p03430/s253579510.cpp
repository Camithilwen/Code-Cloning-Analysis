#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define mp make_pair
#define inf 998244353
#define LINF 1000000000000000007LL
#define ll long long
using namespace std;
int dp[310][310][310]; 
string s;
int calc( int lef, int rig, int k){
	if( dp[lef][rig][k] != 0){
		return dp[lef][rig][k];
	}
	if( lef == rig ){
		return 1;
	}
	if( lef > rig ){
		return 0;
	}
	else{
		if( s[lef] == s[rig] ){
			dp[lef][rig][k] = calc( lef+1, rig -1, k ) + 2;
			return dp[lef][rig][k];
		}
		else{
			int c1 = -1;
			if( k > 0 ) c1 = calc( lef+1, rig-1, k-1) + 2;
			int c2 = calc( lef+1, rig, k);
			int c3 = calc( lef, rig-1, k);
			dp[lef][rig][k] = max( c1, max(c2,c3) );
			return dp[lef][rig][k];
		}
	}
}
signed main(){
	int k;
	cin >> s;
	cin >> k;
	int n = s.size();
	int ans = calc( 0, n-1, k );
	cout<<ans<<endl;
}