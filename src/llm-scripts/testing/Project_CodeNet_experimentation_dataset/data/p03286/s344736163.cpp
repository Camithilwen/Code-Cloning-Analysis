#include<bits/stdc++.h>
typedef long long ll;
typedef std::pair<ll,ll> P;

#define rep(i,n) for(int i = 0; i < int(n); i++)
using namespace std;

template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

constexpr ll mod = 1e9 + 7;

struct UnionFind {
public:
	vector <ll> par; // 
	vector <ll> siz; // 

	UnionFind() {}

	UnionFind(ll sz_) : par(sz_), siz(sz_, 1LL) {
		for (ll i = 0; i < sz_; ++i) par[i] = i;
	}
	void init(ll sz_) {
		par.resize(sz_);
		siz.assign(sz_, 1LL);
		for (ll i = 0; i < sz_; ++i) par[i] = i;
	}

	ll root(ll x) {
		while (par[x] != x) {
			x = par[x] = par[par[x]];
		}
		return x;
	}

	bool merge(ll x, ll y) {
		x = root(x);
		y = root(y);
		if (x == y) return false;
		if (siz[x] < siz[y]) swap(x, y);
		siz[x] += siz[y];
		par[y] = x;
		return true;
	}

	bool issame(ll x, ll y) {
		return root(x) == root(y);
	}

	ll size(ll x) {
		return siz[root(x)];
	}
};

int main() {
	ll n;
	cin >> n;
	vector<int> ans;
	for (int i = 0; i < 60; i++) {
		ll m = n % (1LL << (i+1));
		if (m) {
			ans.push_back(1);
			ll sub = 1LL << i;
			if (i % 2 == 1) {
				sub *= -1;
			}
			n -= sub;
		}
		else ans.push_back(0);
		if (n == 0) break;
	}
	reverse(ans.begin(), ans.end());
	for (auto a : ans) {
		cout << a;
	}
	cout << endl;
	return 0;
}
