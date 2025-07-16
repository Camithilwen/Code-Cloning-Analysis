#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int dp[2][6005];

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, t;
	cin >> n >> t;
	vector<P> v(n);
	rep(i,n) cin >> v[i].first >> v[i].second;
	sort(v.begin(), v.end());
	rep(i,n){
		int a = v[i].first;
		int b = v[i].second;
		rep(j,6001){
			chmax(dp[(i+1)%2][j], dp[i%2][j]);
			if(j < t) chmax(dp[(i+1)%2][j+a], dp[i%2][j] + b);
		}
	}
	int ans = 0;
	rep(j,6001) chmax(ans, dp[n%2][j]);
	cout << ans << endl;
	return 0;
}
