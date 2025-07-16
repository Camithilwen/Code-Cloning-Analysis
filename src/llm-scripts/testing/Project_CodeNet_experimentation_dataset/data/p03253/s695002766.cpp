#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
#define all(x) (x).begin(), (x).end()
#define fsp(x) fixed << setprecision(x)
const ll inf = LLONG_MAX;
const long double pi = acos(-1);
void Yes() {cout << "Yes" << endl;}
void No() {cout << "No" << endl;}
void YES() {cout << "YES" << endl;}
void NO() {cout << "NO" << endl;}

//素数判定
//#include <cmath>
bool is_prime(long long n) {
	if (n == 1) return false;
	if (n == 2) return true;
	if (n % 2 == 0) return false;
	for (long long i = 3; i <= sqrt(n); i += 2) {
		if (n % i == 0) return false;
	}
	return true;
}

//二項係数 mod p
//#include <vector>
long long modinv(long long n, long long p) {
	long long a = p, u = 1, v = 0;
	while (a) {
		long long t = n / a;
		n -= t * a;
		std::swap(n, a);
		u -= t * v;
		std::swap(u, v);
	}
	u %= p;
	if (u < 0) u += p;
	return u;
}

std::vector<long long> factorial;
std::vector<long long> factorial_inv;
void make_table(long long n, long long p) {
	factorial.resize(n, 1);
	factorial_inv.resize(n, 1);
	for (long long i = 2; i <= n; i++) {
		factorial[i] = factorial[i - 1] * i % p;
	}
	factorial_inv[n] = modinv(factorial[n], p);
	for (long long i = n - 1; i >= 2; i--) {
		factorial_inv[i] = factorial_inv[i + 1] * (i + 1) % p;
	}
}

long long combination(long long n, long long r, long long p) {
	r = std::min(r, n - r);
	long long ret = factorial[n] * factorial_inv[r] % p;
	ret *= factorial_inv[n - r];
	ret %= p;
	return ret;
}

int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	const ll p = 1e9 + 7;
	//const ll p = 998244353;

	ll n, m;
	cin >> n >> m;

	map<ll, ll> mp;
	ll x = m;
	for (ll i = 2; i <= x; i++) {
		if (is_prime(x)) {
			mp[x]++;
			break;
		}
		if (!is_prime(i)) continue;
		ll cnt = 0;
		while (x % i == 0) {
			x /= i;
			cnt++;
		}
		mp[i] += cnt;
	}

	make_table(1e7, p);
	ll ans = 1;
	for (auto i = mp.begin(); i != mp.end(); i++) {
		ll a = (i -> first), b = (i -> second);
		ans *= combination(b + n - 1, n - 1, p);
		ans %= p;
	}
	cout << ans << endl;
}
