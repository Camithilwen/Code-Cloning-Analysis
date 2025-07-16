#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

const ll MOD = 1000000007;

int main() {
	ll N;
	cin >> N;

	vector <ll> A(N);
	for (int ii = 0; ii < N; ++ii){
		cin >> A[ii];
	}

	ll ans = 0;
	vector <ll> digZero(61);
	vector <ll> digOne(61);
	for (int ii = 0; ii < N; ++ii){
		ll keta = 0;
		ll val = 1;
		for (int jj = 0; jj < 61; ++jj){
			ll tmp = A[ii] & 1;
			if (tmp == 0){
				ans = (ans + val * digOne[keta]) % MOD;
				digZero[keta] = (digZero[keta] + 1) % MOD;
			} else {
				ans = (ans + val * digZero[keta]) % MOD;
				digOne[keta] = (digOne[keta] + 1) % MOD;
			}
			val = (val * 2) % MOD;
			keta++;
			A[ii] /= 2;
		}
	}

	cout << ans << "\n";

	return 0;
}
