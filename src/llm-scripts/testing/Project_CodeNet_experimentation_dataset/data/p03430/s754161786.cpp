#include <bits/stdc++.h>
#if defined(__GNUC__)
#pragma GCC optimize ("Ofast")
#endif
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 310, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
int dp[MAXN][MAXN][MAXN];
string S;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>S>>k;
	n=S.size();
	S="."+S;
	for (int i=n; i; i--){
		for (int x=0; x<=k; x++) dp[i][i][x]=1;
		for (int j=i+1; j<=n; j++){
			dp[i][j][0]=max(dp[i+1][j][0], dp[i][j-1][0]);
			if (S[i]==S[j]) dp[i][j][0]=max(dp[i][j][0], dp[i+1][j-1][0]+2);
			for (int x=1; x<=k; x++){
				dp[i][j][x]=max(dp[i+1][j][x], dp[i][j-1][x]);
				dp[i][j][x]=max(dp[i][j][x], 2+dp[i+1][j-1][x-(S[i]!=S[j])]);
			}
		}
	}
	cout<<dp[1][n][k]<<'\n';
	
	return 0;
}
