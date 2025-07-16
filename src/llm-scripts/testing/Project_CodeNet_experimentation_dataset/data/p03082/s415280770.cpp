#include<iostream>
#include<algorithm>
#include<functional>

using namespace std;

typedef long long ll;

const ll MOD = 1000000007;

int N, X;
ll S[200];

ll dp[201][100000 + 1];

int main() {
	cin >> N >> X;
	for (int i = 0; i < N; i++)cin >> S[i];
	sort(S, S + N, greater<ll>());

	dp[0][X] = 1;
	for (int i = 0; i < N; i++) {
		for (int amari = 0; amari <= X; amari++) {
			//今見てるのを確定減少列にいれる
		//	if (amari >= S[i] ) {
				dp[i + 1][amari % S[i]] += dp[i][amari];
				dp[i + 1][amari % S[i]] %= MOD;
		//	}
			//いれない
			dp[i + 1][amari] += dp[i][amari] * (N - 1 - i);
			dp[i + 1][amari] %= MOD;
		}
	}
	ll ans = 0;

	for (int i = 0; i <= X; i++) {
		ans += i * dp[N][i];
		ans %= MOD;
	}
	cout << ans << endl;

	return 0;
}