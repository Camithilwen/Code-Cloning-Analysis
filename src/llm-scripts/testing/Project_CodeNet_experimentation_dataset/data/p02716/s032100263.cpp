#pragma GCC optimize ("O3")
#pragma GCC target ("avx2")
//#include<bits/stdc++.h>
#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep1(i, n) for(int i = 1; i <= (n); i++)
#define co(x) cout << (x) << "\n"
#define cosp(x) cout << (x) << " "
#define ce(x) cerr << (x) << "\n"
#define cesp(x) cerr << (x) << " "
#define pb push_back
#define mp make_pair
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define Would
#define you
#define please


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);


	int N;
	cin >> N;

	ll dp[2][3];
	dp[0][0] = 0;
	dp[0][1] = -1e18;
	dp[0][2] = -1e18;
	dp[1][0] = -1e18;
	dp[1][1] = -1e18;
	dp[1][2] = -1e18;

	int n = N / 2;
	if (N % 2) {
		rep(i, n) {
			int a, b;
			cin >> a >> b;
			chmax(dp[1][1], dp[0][0]);
			dp[0][0] += a;
			dp[0][2] += a;
			chmax(dp[0][2], dp[1][1]);
			dp[1][1] += b;
		}
		int a;
		cin >> a;
		chmax(dp[1][1], dp[0][0]);
		dp[0][2] += a;
		printf("%lld\n", max(dp[0][2], dp[1][1]));
	}
	else {
		rep(i, n) {
			int a, b;
			cin >> a >> b;
			chmax(dp[1][1], dp[0][0]);
			dp[0][0] += a;
			dp[1][1] += b;
		}
		printf("%lld\n", max(dp[1][1], dp[0][0]));
	}


	Would you please return 0;
}