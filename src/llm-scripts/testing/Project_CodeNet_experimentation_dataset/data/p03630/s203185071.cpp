#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin; using std::cout;
const int maxn = 2020;
typedef long long ll;
const int mod = 998244353;
 inline ll pow(ll a,int b,int ans = 1) {
	for(;b;b >>= 1,a = a * a % mod) if(b & 1)
		ans = ans * a % mod;
	return ans;
 }
 inline ll inverse(int x){ return pow(x, mod - 2); }
int h, w;
char ch[maxn][maxn];
int right[maxn][maxn];
int down[maxn][maxn];
int can[maxn][maxn];

inline int calc(int * a) {
	auto min = [&](int x,int y){ return a[x] < a[y] ? x : y; };
	static int st[20][maxn];
	int ret = 0;
	for(int i = 1;i < h;++i) st[0][i] = i;
	for(int i = 1;i < 13;++i) for(int j = 1;j + (1 << i) - 1 < h;++j) {
		st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << i - 1)]);
	}
	std::function<void(int, int)> solve = [&](int l,int r) {
		if(l > r) return ;
		const int lg = std::__lg(r - l + 1);
		int mn = min(st[lg][l], st[lg][r - (1 << lg) + 1]);
		ret = std::max(ret, (a[mn] + 1) * (r - l + 2));
		solve(l, mn - 1), solve(mn + 1, r);
	};
	solve(1, h - 1);
	return ret;
}
int main() {
	  std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> h >> w;
	rep(i, 1, h) cin >> ch[i] + 1;
	for(int i = h - 1;i >= 1;--i) {
		for(int j = w - 1;j >= 1;--j) {
			can[i][j] = !(ch[i][j] + ch[i + 1][j] + ch[i][j + 1] + ch[i + 1][j + 1] & 1);
			right[j][i] = can[i][j] ? right[j + 1][i] + 1 : 0;
		}
	}
	int ans = w;
	rep(i, 1, w - 1) ans = std::max(ans, calc(right[i]));
	cout << ans << '\n';
}
