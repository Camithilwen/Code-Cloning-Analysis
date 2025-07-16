#include<iostream>
#include<algorithm>
 
using namespace std;
typedef long long ll;
 
int N, K;
const ll MOD = 998244353;
ll F[4002], F_inv[4002];
 
ll modpow(ll a, ll b) {
	ll rtn = 1, kakeru = a;
	while (b > 0) {
		if (b & 1)rtn *= kakeru;
		kakeru *= kakeru;
		kakeru %= MOD;
		rtn %= MOD;
		b >>= 1;
	}
	return rtn;
}
 
void calc_fac() {
	F[0] = 1, F[1] = 1;
	for (int i = 2; i <= 4001; i++) {
		F[i] = F[i - 1] * i;
		F[i] %= MOD;
	}
 
	F_inv[4001] = modpow(F[4001], MOD - 2);
	for (int j = 4000; j >= 0; j--) {
		F_inv[j] = F_inv[j + 1] * (j + 1);
		F_inv[j] %= MOD;
	}
 
}
 
ll comb(ll a, ll b) {
	if (a < 0)return 0;
	if (b < 0)return 0;
	if (b > a)return 0;
	ll ans = (F[a] * F_inv[b])%MOD * F_inv[a - b];
	return ans % MOD;
}
 
ll hcomb(ll a, ll b) {
	return comb(a + b - 1, b);
}
 
int main() {
 
	calc_fac();
 
	cin >> K >> N;
	
	for (int i = 2; i <= 2 * K; i++) {
		if (i % 2 == 1) {
			ll cnt = 0;
			int A = min((i - 1) / 2, (2 * (K + 1) - i) / 2);
			for (int j = 0; j <= A; j++) {
				ll tmp = 1;
				tmp *= (modpow(2, j) * comb(A, j)) % MOD;
				tmp *= hcomb(K - 2 * A + j, N - j);
				tmp %= MOD;
				cnt += tmp;
				cnt %= MOD;
			}
			cout << cnt << endl;
		}
		else {
			ll cnt = 0;
			int A = min((i) / 2, (2 * (K + 1) - i) / 2) - 1;
			for (int j = 0; j <= A; j++) {
				ll tmp = 1;
				tmp *= (modpow(2, j) * comb(A, j)) % MOD;
				ll a = hcomb(K - 2 * A + j - 1, N - j) + hcomb(K - 2 * A + j - 1, N - j - 1);
				a %= MOD;
				tmp *= a;
				tmp %= MOD;
				cnt += tmp;
				cnt %= MOD;
			}
			cout << cnt << endl;
		}
	}
 
	return 0;
}