#include <bits/stdc++.h>
#define rep(i,n) for(int i=(0);i<(n);i++)

using namespace std;

typedef long long ll;

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<ll> a(n);
	rep(i, n) cin >> a[i];


	ll dp[n+1][6];
	ll INF = 1e18;

	rep(i, n+1) rep(j, 3) dp[i][j] = -INF;
	rep(i, 3) if(i < n) dp[i][i] = a[i];
	
	rep(i, n) rep(j, 3){
		for(int d = 0; j + d < 3; d++){
			int bef = i - 2 - d;
			if(bef < 0) continue;
			chmax(dp[i][j+d], dp[bef][j] + a[i]);
		}
	}

	ll ans = -INF;
	int d = 1 + n%2;
	rep(i, d+1){
		int j = n - 1 - i;
		if(j >= 0) chmax(ans, dp[j][d - i]);
	}

	cout << ans << endl;
}
