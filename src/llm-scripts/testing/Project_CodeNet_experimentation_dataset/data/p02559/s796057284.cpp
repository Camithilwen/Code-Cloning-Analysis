#include <bits/stdc++.h>
#include "atcoder/fenwicktree.hpp"
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)

using namespace std;
using namespace atcoder;
using ll = long long;

int main() {
	int n, q;
	cin >> n >>q;
	fenwick_tree<ll> ft(n);
	rep(i, n) {
		ll s;
		cin >> s;
		ft.add(i, s);
	}
	rep(i, q) {
		bool t;
		cin >> t;
		if (!t) {
			int p;
			ll x;
			cin >> p >> x;
			ft.add(p, x);
		}
		else {
			int p, x;
			cin >> p >> x;
			cout << ft.sum(p, x) << endl;;
		}
	}
	return 0;
}
