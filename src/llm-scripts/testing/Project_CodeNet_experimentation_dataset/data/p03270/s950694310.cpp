#include<map>
#include<set>
#include<bitset>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<chrono>
#include<stack>
#include<fstream>
#include<math.h>
#include<list>
#include<complex>
#define REP(i,x,y) for(ll i=x;i<=y;i++)
#define SIZE(a) ll(a.size())
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define vtype(type) vector<type>
#define vvtype(type) vector<vector<type>>
#define MEMSET(a, n, m) for(ll i=0;i<=n;i++) a[i] = m
#define BIT(n) (ll(1)<<n)
#define UNIQUE(v) v.erase(unique(v.begin(),v.end()),v.end()) 
#define UNIQUE_ARRAY(a,x) unique(a + 1, a + x + 1) - a - 1
#define SORT(a,n) sort(a+1,a+n+1)
#define SORT_O(a,n,order) sort(a+1,a+n+1,order)
#define PER(i,y,x) for(ll i=y;i>=x;i--)
typedef long long ll;
using namespace std;
struct wall
{
	long long r; ll c;
	bool operator<(const wall& rhs) const {
		if (r != rhs.r) {
			return r < rhs.r;
		}
		else {
			return c < rhs.c;
		}
	}
};



ll const MOD = 998244353;
ll mod_p(ll x, ll y) {
	//x %= MOD;
	//y %= MOD;
	return (x + y + MOD) % MOD;
}

ll mod_m(ll x, ll y) {
	x %= MOD;
	y %= MOD;
	return x * y%MOD;
}

ll mod_pow(ll x, ll t) {
	x %= MOD;
	if (t == 0) {
		return 1;
	}
	else {
		ll v = mod_pow(x, t / 2);
		if (t % 2 == 0) {
			return v * v % MOD;
		}
		else {
			return v * v%MOD * x %MOD;
		}
	}
}

ll mod_inv(ll x) {
	return mod_pow(x, MOD - 2);
}

vll fct(1e7 + 5);
vll fct_inv(1e7 + 5);

void fct_init() {
	fct[0] = fct_inv[0] = 1;
	REP(i, 1, 1e6) {
		fct[i] = mod_m(fct[i - 1], i);
		fct_inv[i] = mod_inv(fct[i]);
	}
}

ll c(ll n, ll r) {
	return mod_m(fct[n], mod_m(fct_inv[r], fct_inv[n - r]));
}

ll h(ll n, ll r) {
	return c(n - 1 + r, r - 1);
	
}

ll f(ll n, ll k, ll t, ll x) {
	ll ans = 0;
	ll sign = 1;
	REP(i, 0, x) {
		ll tmp = 0;
		if (n - 2 * i < 0) {
			break;
		}
	//	cout << "h " << h(n - 2 * i, k) << " " << c(x, i) << endl;
		tmp = mod_m(h(n - 2 * i, k), c(x, i));
		ans = mod_p(ans, sign*tmp);
		sign *= -1;
		//cout << ans << "?" << endl;
	}
	return ans;
}


int main() {
	ll n, k;
	cin >> k >> n;
	if (k == 1) {
		cout << 0 << endl;
		return 0;
	}
	fct_init();
	REP(t, 2, 2 * k) {
		ll x = 0;
		REP(i, 1, t) {
			ll j = t - i;
			if (i < j && j <= k) {
				x++;
			}
			if (i >= j) break;
		}
		//cout << x << "!" << endl;
		if (t % 2 == 1) {
			ll ans = f(n, k, t, x);
			cout << ans << endl;
		}
		else {
			ll u = f(n, k - 1, t, x);
			ll v = f(n - 1, k - 1, t, x);
			ll ans = mod_p(u, v);
			cout << ans << endl;
		}
	}
}