#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define INF 1000000000000000LL
#define N 5010
int n;
PII a[N];
ll f[N], g[N]; // min height

bool cmp(PII x, PII y) {
	return x.fi + x.se < y.fi + y.se || x.fi + x.se == y.fi + y.se && x.se < y.se;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i ++)
		cin >> a[i].fi >> a[i].se;
	sort(a, a+n, cmp);
	for (int i = 0; i <= n; i ++) f[i] = INF;
	f[0] = 0;
	for (int i = 0; i < n; i ++) {
		memcpy(g, f, sizeof g);
		for (int j = 0; j <= n; j ++) f[j] = INF;
		for (int j = 0; j <= n; j ++) if (g[j] < INF) {
			if (g[j] <= a[i].fi) f[j+1] = min(f[j+1], g[j] + a[i].se);
			f[j] = min(f[j], g[j]);
		}
	}
	int S = 0;
	for (int i = 0; i <= n; i ++)
		if (f[i] < INF) S = max(S, i);
	cout << S << endl;
	return 0;
}