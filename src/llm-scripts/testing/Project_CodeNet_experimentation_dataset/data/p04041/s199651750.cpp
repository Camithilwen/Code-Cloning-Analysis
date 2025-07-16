#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>

#define MP std::make_pair
#define rep(i, l, r) for (int i = (l); i <= (r); ++ i)
#define per(i, r, l) for (int i = (r); i >= (l); -- i)
#define PE(x, a) for (int x = head[a]; x;x = edge[x].next)
#define pb push_back
#define CL(a, b) memset(a, b, sizeof a)
#define PII std::pair<int, int>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()

typedef long long ll;

const ll HA = 1e9 + 7;

ll f[45][(1 << 17) + 7];
int n, x, y, z;

int main() {
	scanf("%d %d %d %d", &n, &x, &y, &z);
	int st = (1 << (z - 1)) | (1 << (z + y - 1)) | (1 << (z + y + x - 1));
	int lim = (1 << (x + y + z)) - 1;
	f[0][0] = 1;
	rep(i, 1, n) {
		rep(s, 0, lim) {
			if ((s & st) != st && f[i - 1][s])
			rep(c, 1, 10) {
				f[i][lim & ((s << c) | (1 << c - 1))] = (f[i][lim & ((s << c) | (1 << c - 1))] + f[i - 1][s]) % HA;
			}
		}
	}
	ll ans  = 0;
	rep(i, 0, lim) if ((i & st) != st) ans = (ans + f[n][i]) % HA;
	ll tmp = 1;
	rep(i, 1, n) tmp = tmp * 10 % HA;
	ans = (tmp - ans + HA) % HA;
	printf("%lld\n", ans);
	return 0;
}