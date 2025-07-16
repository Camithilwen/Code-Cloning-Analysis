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

const ll mod = 998244353;

int cnt[100005], t[100005];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int n; read(n);
	int mx = 0;

	rep(i, 0, n) {
		read(t[i]);
		chmax(mx, t[i]);
		cnt[t[i]]++;
	}

	if (t[0] != 0 || cnt[0] != 1)
		die(0);

	ll ans = 1;

	rep(i, 1, mx + 1) {
		rep(j, 0, cnt[i])
			ans = ans * cnt[i - 1] % mod;
	}

	die(ans);
}
