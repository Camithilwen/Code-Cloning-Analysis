#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define all(x) (x).begin(),(x).end()
#define V vector
typedef V<int> vi;
typedef V<vi> vvi;
typedef long long ll;
typedef pair<int, int> P;
constexpr auto INF = INT_MAX/2;
constexpr auto LINF = 5000000000000000;
constexpr auto MOD = 1000000007;

ll fac[120020], invfac[120020];

ll lpow(ll p, ll q) {
	ll ans = 1;
	ll pp = p;
	while (q) {
		if (q % 2) {
			ans *= pp;
			ans %= MOD;
		}
		q /= 2;
		pp *= pp;
		pp %= MOD;
	}
	return ans;
}

ll com(ll n, ll r) {
	if (n < r || n < 0 || r < 0)return 0;
	ll ans = 1;
	ll k = n - r;

	ans *= fac[n] * invfac[r];
	ans %= MOD;
	ans *= invfac[k];
	ans %= MOD;

	return ans;
}

void precom(int n) {
	rep(i, n + 1) {
		if (i == 0)fac[i] = 1;
		else fac[i] = (fac[i - 1] * i) % MOD;
		invfac[i] = lpow(fac[i], MOD - 2);
	}
	return;
}

int s[100020];
vi prime(0);

int main() {

	ll n, m;
	cin >> n >> m;

	if (m == 1 || n == 1) { cout << 1 << endl;return 0;
	}
	rep(i, 100020)s[i] = 1;
	rep1(i, 100000) {
		if (i < 2)continue;
		if (s[i] != 1)continue;

		prime.push_back(i);
		s[i] = i;
		int ii = i;
		while (ii <= 100000) {
			if (s[ii] == 1)s[ii] = i;
			ii += i;
		}
	}
	precom(120000);

	vi mp(0);

	int mm = m;
	int k = 0;
	while (mm>1&&k<prime.size()) {
		if (mm % prime[k])k++;
		else { mm /= prime[k];mp.push_back(prime[k]); }
	}
	if(mm>1)mp.push_back(mm);

	k = 1;
	ll ans = 1;
	rep(i, mp.size() - 1) {
		if (mp[i + 1] == mp[i])k++;
		else {
			ans *= com(n - 1 + k, k);
			ans %= MOD;
			k = 1;
		}
	}
	ans *= com(n - 1 + k, k);
	ans %= MOD;
	cout << ans << endl;

}