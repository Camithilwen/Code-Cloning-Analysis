#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin; using std::cout;
const int maxn = 15;
int n, m;
int f[maxn][1 << maxn];
int edge[maxn][maxn];
int g[1 << maxn];
inline void up(int & x,int y) {
	if(x < y) {
		x = y;
	}
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	int sum = 0;
	rep(i, 1, m) {
		int a, b, c;
		cin >> a >> b >> c;
		-- a, -- b;
		edge[a][b] = c;
		edge[b][a] = c;
		for(int j = 0;j < 1 << n;++j) if(j >> a & j >> b & 1) {
			g[j] += c;
		}
		sum += c;
	}
	for(int i = 0;i < n;++i) {
		for(int j = 0;j < 1 << n;++j) {
			f[i][j] = -1e9;
		}
	}
	for(int i = 1;i < 1 << n;i += 2)
		f[0][i] = g[i];
	for(int j = 0;j < 1 << n;++j) {
		for(int i = 0;i < n;++i) if(f[i][j] >= 0) {
			for(int l = 0;l < n;++l) if(edge[i][l] && !(j >> l & 1)) {
				for(int s = ~(j | 1 << l) & (1 << n) - 1, k = s;k;k = k - 1 & s) {
					up(f[l][k | j | 1 << l], f[i][j] + edge[i][l] + g[k | 1 << l]);
				}
				up(f[l][j | 1 << l], f[i][j] + edge[i][l]);
			}
		}
	}
	cout << sum - f[n - 1][(1 << n) - 1] << '\n';
}
