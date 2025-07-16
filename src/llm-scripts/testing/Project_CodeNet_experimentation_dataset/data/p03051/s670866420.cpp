#include <stdio.h>
#include <algorithm>
using namespace std;
using ll = long long;

int n, a[500010], ca[500010];
ll czero[500010], dp[1 << 20][2], last[1 << 20], mod = 1e9+7;
void zero() {
	for (int i = 0; i < (1 << 20); i++)
		dp[i][0] = 1, last[i] = 0;
	for (int i = 1; i <= n; i++) {
		czero[i] = czero[i - 1];
		if (ca[i] != 0) {
			dp[ca[i]][0] += dp[ca[i]][1] * (czero[i] - czero[last[ca[i]]]);
			dp[ca[i]][0] %= mod;

			dp[ca[i]][1] += dp[ca[i]][0];
			dp[ca[i]][1] %= mod;

			last[ca[i]] = i;
		}
		else
			czero[i]++;
	}
	ll sum = 0;
	for (int i = 1; i < (1 << 20); i++)
		sum += dp[i][1];
	ll pow2 = 1;
	for (int i = 0; i < czero[n] - 1; i++)
		pow2 = (pow2 * 2) % mod;
	sum += pow2;
	sum = ((sum % mod) + mod) % mod;
	printf("%lld\n", sum);
}
void nonzero() {
	for (int i = 0; i < (1 << 20); i++)
		dp[i][0] = 1, last[i] = 0;
	for (int i = 1; i <= n; i++) {
		czero[i] = czero[i - 1];
		if (ca[i] != 0) {
			dp[ca[i]][0] += dp[ca[i]][1] * (czero[i] - czero[last[ca[i]]]);
			dp[ca[i]][0] %= mod;

			dp[ca[i]][1] += dp[ca[i]][0];
			dp[ca[i]][1] %= mod;

			last[ca[i]] = i;
		}
		else
			czero[i]++;
	}
	printf("%lld\n", dp[ca[n]][0]);
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		ca[i] ^= ca[i - 1] ^ a[i];
	}

	if (ca[n] == 0)
		zero();
	else
		nonzero();
}