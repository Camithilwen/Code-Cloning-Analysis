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
#define Would
#define you
#define please

ll mod = 998244353;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);


	int N;
	cin >> N;
	int A[300];
	rep(i, N) cin >> A[i];

	int goukei = 0;
	rep(i, N) goukei += A[i];
	int goukei2 = 0;
	ll dp[45001][301] = {};
	dp[0][0] = 1;
	ll dp2[301] = {};
	rep(i, N) {
		for (int k = i; k >= 0; k--) if (dp2[k]) {
			dp2[k + 1] += dp2[k];
			dp2[k + 1] %= mod;
		}
		int x = max(0, goukei2 - goukei / 2);
		for (int j = min(goukei2, (goukei + 1) / 2 - 1); j >= x; j--) {
			for (int k = i; k >= 0; k--) {
				if (dp[j][k]) {
					if (j + A[i] >= (goukei + 1) / 2) dp2[k + 1] = (dp2[k + 1] + dp[j][k]) % mod;
					else dp[j + A[i]][k + 1] = (dp[j + A[i]][k + 1] + dp[j][k]) % mod;
				}
			}
		}
		goukei2 += A[i];
	}

	ll zenbu = 1;
	rep(i, N) {
		zenbu *= 3;
		zenbu %= mod;
	}
	ll bairitu[301];
	bairitu[0] = 1;
	rep(i, 300) {
		bairitu[i + 1] = 2 * bairitu[i] % mod;
	}

	ll dame = 0;
	rep1(k, N - 1) {
		if (dp2[k]) {
			int k2 = N - k;
			ll kari = dp2[k] * bairitu[k2] % mod;
			kari -= 2 * dp2[k];
			dame += kari + mod;
			dame %= mod;
		}
	}

	dame *= 3;
	dame %= mod;

	ll kari = 1;
	rep(i, N) {
		kari *= 2;
		kari %= mod;
	}
	dame += kari * 3;
	dame %= mod;

	co((zenbu - dame + mod + 3) % mod);

	Would you please return 0;
}