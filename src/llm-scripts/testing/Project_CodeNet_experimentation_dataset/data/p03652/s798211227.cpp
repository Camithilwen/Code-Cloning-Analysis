#include <bits/stdc++.h>
#define inf 0x3f3f3f3f3f3f3f3f
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define fi first
#define se second
#define N 305

using namespace std;
typedef pair<int,int> Pair;
const int mod = 1e9 + 7;
inline int add(int x, int y) { return (x += y) - (x >= mod ? mod : 0); }
inline void inc(int &x, int y) { (x += y) -= (x >= mod ? mod : 0); }
inline int mul(int x, int y) { return 1ll * x * y % mod; }

template <class T> inline T	input() {
	int x; char ch; while (!isdigit(ch = getchar()));
	for (x = ch ^ 48; isdigit(ch = getchar()); x = x * 10 + (ch ^ 48));
	return x;
}

template <class T> inline void chkmin(T &x, T &y) { x = x < y ? x : y; }
template <class T> inline void chkmax(T &x, T &y) { x = x > y ? x : y; }

struct {
	inline operator int () { return input<int>(); }
	inline operator long long () { return input<long long>(); }
	template <class T> inline void operator () (T &x) { x = *this; }
	template<class T, class ...A> inline void operator () (T &x, A &...a)
	{ x = *this; this -> operator ()(a...); }
} read;

int n, m, ans = inf;
int a[N][N];
int cnt[N];
bool vis[N];

void calc() {
	memset(cnt, 0, sizeof cnt);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (vis[a[i][j]]) {
				++cnt[a[i][j]];
				break;
			}
}

int main() {
	read(n, m);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			read(a[i][j]);

	for (int i = 1; i <= m; ++i) vis[i] = true;
	calc();

	for (int i = 1; i <= m; ++i) {
		int pos = max_element(cnt + 1, cnt + m + 1) - cnt;
		ans = min(ans, cnt[pos]);
		vis[pos] = false;
		calc();
	}

	printf("%d\n", ans);
	return 0;
}
