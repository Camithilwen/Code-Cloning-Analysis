#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <queue>
#include <fstream>
#include <string>
#include <math.h>
#include <set>
#include <string>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
//typedef pair<ll, P> T;

#define rep(i, n) for (ll i = 0; i < (n); i++)
#define revrep(i, n) for (ll i = (n) - 1; i >= 0; i--)
#define f first
#define s second
#define pb push_back

ll mod = 2147483647;
const ll INF = 100000000000010000;
const ull B = 998244353;

//ll bit[200010];
//ll kai[3010];

//void pres(double A, ll x = 20) { printf("%.20f\n", x); }

/*ll sum(ll i)
{
	i += 1;
	ll t = 0;
	while (i > 0)
	{
		t += bit[i];
		i -= i & -i;
	}
	return t;
}

void update(ll i, ll x)
{
	i += 1;
	while (i <= 200005)
	{
		bit[i] += x;
		i += i & -i;
	}
}*/

/*`ll SAIKI(ll S) {
	for (ll T = S; ; T = (T - 1) & S) {

	}
}*/

void test() {
	cout << "888888888888888888888888" << endl;
}

ll gcd(ll x, ll y) {
	if (y == 0) return x;
	return gcd(y, x % y);
}

ll pow_mod(ll x, ll y) {
	if (y == 0) return 1;
	if (y % 2 == 1) {
		return x * pow_mod(x, y - 1) % mod;
	}
	else {
		ll half = pow_mod(x, y / 2);
		return half * half % mod;
	}
}

ll div_mod(ll x) {
	return pow_mod(x, mod - 2);
}

/*ll com(ll x, ll y) {
	return kai[x] * div_mod(kai[y] * kai[x - y] % mod) % mod;
	//毎回オーダーlog(n)かかる
}*/

/*void kaijo() {
	kai[0] = 1;
	for (ll i = 1; i <= 3004; i++) {
		kai[i] = kai[i - 1] * i % mod;
	}
}*/

ll N, A[100010], sum, resum;
ll hakidashi[60];
vector<P> trans;
ll ans;

void solve() {
	cin >> N;
	rep(i, N) cin >> A[i];
	rep(i, N) sum ^= A[i];
	resum = sum ^ ((1LL << 60) - 1);
	rep(i, N) A[i] &= resum;
	priority_queue<ll> que;
	ll bit = 59;
	rep(i, N)if (A[i] != 0) que.push(A[i]);
	while (que.size()) {
		ll lar = que.top(); que.pop();
		while ((lar & (1LL << bit)) == 0 && bit >= 0) bit--;
		if (bit < 0) break;
		hakidashi[bit] = lar;
		while (que.size() && que.top() > (1LL << bit)) {
			ll a = que.top(); que.pop();
			que.push(a ^ hakidashi[bit]);
		}
	}
	rep(i, 60)if (hakidashi[i] != 0) trans.pb(P(hakidashi[i], i));
	for (ll i = 0; i < trans.size(); i++) {
		for (ll j = i + 1; j < trans.size(); j++) {
			P p = trans[i], q = trans[j];
			if ((q.f & (1LL << p.s)) != 0) trans[j].f ^= p.f;
		}
	}
	for (P p : trans) ans ^= p.f;
	ans = ans * 2 + sum;
	cout << ans << endl;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	solve();
	ll N;
	cin >> N;
}