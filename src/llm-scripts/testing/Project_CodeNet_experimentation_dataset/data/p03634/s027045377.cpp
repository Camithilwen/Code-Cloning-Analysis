#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define maxs(a, b) a = max(a, b)
#define mins(a, b) a = min(a, b)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const ll linf = (1ll << 61);
const int inf = 1001001001;
const int mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<vector<P>> g(n);
	rep(i, n - 1) {
		int a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		g[a].push_back(P(b, c));
		g[b].push_back(P(a, c));
	}
	int q, k;
	cin >> q >> k;
	k--;
	priority_queue<P, vector<P>, greater<P>> pq;
	vector<ll> d(n, linf);
	pq.emplace(0, k);
	d[k] = 0;
	while (pq.size()) {
		P p = pq.top(); pq.pop();
		int v = p.second;
		if (d[v] < p.first) continue;
		for (auto c : g[v]) {
			if (d[c.first] > d[v] + c.second) {
				d[c.first] = d[v] + c.second;
				pq.emplace(d[c.first], c.first);
			}
		}
	}
	while (q--) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		cout << d[x] + d[y] << endl;
	}
	return 0;
}
