#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

const int MN = 100010;

int n, m;
int c0;

int st[MN];
int bi_comp, bi_v;
int nbi_comp, nbi_v;
vi g[MN];

int sz;

bool dfs(int v, int c) {
	st[v] = c;
	++sz;

	bool flg = true;

	for (int to : g[v]) {
		if (st[to] == -1) {
			if (!dfs(to, c ^ 1)) {
				flg = false;
			}
		} else {
			if (st[to] == c) {
				flg = false;
			}
		}
	}

	return flg;
}

int main() {
	cin >> n >> m;

	rep(i, m) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		g[a].pb(b); g[b].pb(a);
	}

	memset(st, -1, sizeof(st));

	rep(i, n) {
		if (st[i] == -1) {
			if (g[i].size() == 0) {
				++c0;
			} else {
				sz = 0;
				bool res = dfs(i, 0);

				if (res) {
					++bi_comp;
					bi_v += sz;
				} else {
					++nbi_comp;
					nbi_v += sz;
				}
			}
		}
	}

	ll ret = (ll)n * n - (ll)(n - c0) * (n - c0) + (ll)bi_comp * bi_comp * 2 + 2LL * nbi_comp * bi_comp + (ll)nbi_comp * nbi_comp;

	cout << ret << endl;
	return 0;
}