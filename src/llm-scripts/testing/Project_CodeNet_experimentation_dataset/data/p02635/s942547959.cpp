#pragma GCC optimize ("O2")
#pragma GCC target ("avx2")
#include<bits/stdc++.h>
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

const ll mod = 998244353;

ll dp[310][310];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);


	string S;
	int K;
	int k = 0;
	int A[301] = {};

	cin >> S >> K;
	rep(i, S.size()) {
		if (S[i] == '0') k++;
		else {
			A[k]++;
		}
	}

	int kosuu = 0;
	dp[0][0] = 1;
	for (int i = k; i >= 0; i--) {
		for (int j = kosuu; j >= 0; j--) {
			ll tmp = 0;
			for (int k = kosuu; k >= 0; k--) {
				dp[j][k] %= mod;
				tmp += dp[j][k];
				rep1(p, A[i]) dp[j + p][k + p] += dp[j][k];
				dp[j][k] = tmp;
			}
		}
		kosuu += A[i];
	}

	ll kotae = 0;
	rep(i, min(K, kosuu) + 1) {
		kotae += dp[i][0] % mod;
	}
	co(kotae % mod);



	Would you please return 0;
}
