#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define ff first
#define ss second

typedef long long ll;
const ll MAXN = 2e6 + 10, inf = 1e18, mod = 1e9 + 7;

struct pair_hash {
	template <class T1, class T2>
	std::size_t operator () (const std::pair<T1,T2> &p) const {
		auto h1 = std::hash<T1>{}(p.first);
		auto h2 = std::hash<T2>{}(p.second);

		return h1 ^ h2;  
	}
};

ll pw(ll te, ll tee) {
	if (tee == 0)	return 1;
	ll res = pw(te, tee / 2);
	return (tee % 2 ? te * res * res : res * res);
}
ll k, a[60];

void Read_input() {
	cin >> k;
	if (k == 0) {
		cout << 4 << endl;
		cout << 3 << " " << 3 << " " << 3 << " " << 3;
		exit(0);
	}
}

void Solve() {
	for (ll i = 1; i <= 50; i++)	a[i] = i - 1;
	ll t = (k - 1) / 50;
	k %= 50;
	for (ll i = 1; i <= 50; i++)	a[i] += t;
	if (k == 0)
		for (ll i = 1; i <= 50; i++)	a[i]++;
	else {
		for (ll i = 1; i <= k; i++) {
			sort(a + 1, a + 51);
			a[1] += 50;
			for (ll j = 2; j <= 50; j++)	a[j]--;
		}
	}
	cout << 50 << endl;
	cout << a[1];
	for (ll i = 2; i <= 50; i++)	cout << " " << a[i];
}


int main() {

	ios_base::sync_with_stdio(false);	cin.tie(0);	cout.tie(0);
	//freopen("input.txt", "r", stdin),	freopen("output.txt", "w", stdout);

	Read_input(),	Solve();
	return 0;
}