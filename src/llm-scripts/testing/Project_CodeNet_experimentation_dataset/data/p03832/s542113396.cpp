#include <bits/stdc++.h>
#define sp ' '
#define nyan "(=^・ω・^=)"
#define mkp make_pair
#define intmax 2147483647
#define llmax 9223372036854775807
#define lP pair<ll,ll>
#define iP pair<int,int>
typedef long long ll;
using namespace std;
const int mod = 1000000007;

int N, A, B, C, D;
ll DP[1001], E869120[1001];

ll pw(ll x, int y) {
	ll a = 1;
	while (y) {
		if (y & 1)
			a = a * x%mod;
		x = x * x%mod;
		y >>= 1;
	}
	return a;
}
ll modinv(ll x) {
	return pw(x, mod - 2);
}

int main() {
	cin >> N >> A >> B >> C >> D;
	DP[0] = 1;
	E869120[0] = 1;
	for (int i = 1; i != N + 1; ++i)
		E869120[i] = E869120[i - 1] * i%mod;
	for (int i = A; i != B + 1; ++i) {
		for (int j = N; j != -1; --j) {		
			for (int k = C; k != D + 1 && j + i * k <= N; ++k) {
				DP[j + i * k] = (DP[j + i * k] + DP[j] * E869120[N - j] % mod*modinv(E869120[i*k] * E869120[N - j - i * k] % mod*pw(E869120[i], k) % mod*E869120[k] % mod) % mod*E869120[i*k]) % mod;
			}
		}
	}
	cout << DP[N] << endl;
	return 0;
}