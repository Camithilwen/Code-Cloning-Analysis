#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template<typename H> bool chmin(H& v1, const H v2) { if (v1 > v2) { v1 = v2; return true; } return false; }
template<typename H> bool chmax(H& v1, const H v2) { if (v1 < v2) { v1 = v2; return true; } return false; }
template<typename H> void read(H& head) { cin >> head; }
template<typename H, typename ...T> void read(H& head, T& ...tail) { cin >> head; read(tail...); }
template<typename H> void write(H head) { cout << head << '\n'; }
template<typename H, typename ...T> void write(H head, T ...tail) { cout << head << " "; write(tail...); }
template<typename ...T> void die(T ...tok) { write(tok...); exit(0); }

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int n, k; read(n, k);
	vector<int> v(n);

	rep(i, 0, n) read(v[i]);

	ll ans = 0;
	rep(i, 0, min(n, k) + 1) {
		int p = k - i; // put back
		rep(j, 0, i + 1) {
			int left = j, right = i - j;
			multiset<int> m;
			rep(k, 0, left) m.insert(v[k]);
			rep(k, 0, right) m.insert(v[n - 1 - k]);
			rep(k, 0, p) if (m.size() && *m.begin() < 0) m.erase(m.begin());
			ll lans = 0;
			for (int h : m) lans += h;
			chmax(ans, lans);
		}
	}
	die(ans);
}
