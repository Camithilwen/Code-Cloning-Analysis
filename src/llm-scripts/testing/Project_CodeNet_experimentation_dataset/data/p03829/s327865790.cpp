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

int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	const ll p = 1e9 + 7;
	//const ll p = 998244353;

	ll n, a, b;
	cin >> n >> a >> b;
	vll x(n);
	for (ll i = 0; i < n; i++) cin >> x[i];

	ll ans = 0;
	for (ll i = 0; i < n - 1; i++) ans += min(a * (x[i + 1] - x[i]), b);
	cout << ans << endl;
}
