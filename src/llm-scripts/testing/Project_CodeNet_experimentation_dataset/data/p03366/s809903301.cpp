#include <cstdio>
#include <cmath>
#define N 100010
#define ll long long
#define mem(x, a) memset(x, a, sizeof x)
#define mpy(x, y) memcpy(x, y, sizeof y)
#define fo(x, a, b) for (int x = (a); x <= (b); x++)
#define fd(x, a, b) for (int x = (a); x >= (b); x--)
using namespace std;
int n, st, coo[N], go_[N], tot = 0;
ll ans = 0, hav[N];

inline int read() {
	int x = 0, f = 0; char c = getchar();
	while (c < '0' || c > '9') f = (c == '-') ? 1 : f, c = getchar();
	while (c >= '0' && c <= '9') x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
	return f ? -x : x;
}

void dfs(int l, int r) {
	if (l > r) return;
	if (st < coo[l]) dfs(l, r - 1), go_[++tot] = r;
	else if (st > coo[r]) dfs(l + 1, r), go_[++tot] = l;
	else if (hav[l] >= hav[r]) hav[l] += hav[r], dfs(l, r - 1), go_[++tot] = r;
	else hav[r] += hav[l], dfs(l + 1, r), go_[++tot] = l;
}

int main()
{
//	freopen("home.in", "r", stdin);
//	freopen("home.out", "w", stdout);
	n = read(), st = read();
	fo(i, 1, n) coo[i] = read(), hav[i] = read();
	dfs(1, n);
	ans = abs(coo[go_[1]] - st);
	fo(i, 2, n) ans += abs(coo[go_[i]] - coo[go_[i - 1]]);
	printf("%lld\n", ans);
	return 0;
}
