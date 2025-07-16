
// D - Factorization

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;

const int MOD = 1000000007;

vector<pair<ll, ll>> prime_factorize(ll n) {
	vector<pair<ll, ll> > result;
	for (ll p=2; p*p<=n; p++) {
		if (n % p != 0) continue;
		ll num = 0;
		while (n % p == 0) {
			num++;
			n /= p;
		}
		result.push_back(make_pair(p, num));
    }
    if (n != 1) {
    	result.push_back(make_pair(n, 1));
    }
    return result;
}

vector<ll> prime_factorize_straight(ll n) {
	vector<ll> result;
	vector<pair<ll, ll>> pair_result = prime_factorize(n);
	for (auto pair : pair_result) {
		for (ll i=0; i<pair.second; i++) {
			result.push_back(pair.first);
		}
	}

	return result;
}

// mod p （pは素数）の下でのべき乗を求める
ll mod_pow(ll a, ll n, ll p) {
		ll result = 1;
		while (n > 0) {
			if (n & 1) result = result * a % p;
			a = a * a % p;
			n >>= 1;
		}
		return result;
	};

// mod p（pは素数）の下での逆元を求める（フェルマーの小定理を利用）
ll mod_inverse(ll a, ll p) {
	return mod_pow(a, p-2, p);
}

// mod p （pは素数）の下での除算 (a / b)
ll mod_devide(ll a, ll b, ll p) {
	return a * mod_inverse(b, p) % p;
}

ll mod_comb(ll n, ll k, ll p) {
	ll numerator = 1;
	for (int i=n; i>n-k; i--) {
		numerator *= i;
		numerator %= p;
	}

	ll denominator = 1;
	for (int i=k; i>0; i--) {
		denominator *= i;
		denominator %= p;
	}

	return mod_devide(numerator, denominator, p);
}


int main() {
	int N, M;
	cin >> N >> M;

	vector<pair<ll, ll>> pf = prime_factorize(M);

	ll ans = 1;

	for (auto p : pf) {
		int k = p.second;
		ans = (ans * mod_comb(k+N-1, N-1, MOD)) % MOD;
	}

	cout << ans << endl;

	return 0;
}