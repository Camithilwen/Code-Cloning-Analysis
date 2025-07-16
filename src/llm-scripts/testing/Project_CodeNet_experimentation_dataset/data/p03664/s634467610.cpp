#include <bits/stdc++.h>
#define N 20
#define M (1 << 15 | 5)
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
int mp[N][N], inc[M], cot[M][N], dp[M][N];
int main(int argc, char const *argv[]) {
	int n = read(), m = read();
	for (int i = 1; i <= m; i++) {
		int x = read() - 1, y = read() - 1;
		mp[x][y] = mp[y][x] = read();
	}
	int tot = 1 << n;
	for (int i = 0; i < tot; i++)
		for (int a = 0; a < n; a++) if (i >> a & 1)
			for (int b = 0; b < a; b++) if (i >> b & 1)
				if (mp[a][b]) inc[i] += mp[a][b];
	for (int i = 0; i < tot; i++)
		for (int a = 0; a < n; a++) if (~ i >> a & 1)
			for (int b = 0; b < n; b++) if (i >> b & 1)
				if (mp[a][b]) cot[i][a] += mp[a][b];
	memset(dp, -1, sizeof dp);
	dp[1][0] = 0;
	for (int i = 0; i < tot; i++) {
		for (int a = 0; a < n; a++) {
			if ((i >> a & 1) && ~ dp[i][a]) {
				for (int b = 0; b < n; b++) if (~ i >> b & 1)
					if (mp[a][b]) dp[i | (1 << b)][b] = max(dp[i | (1 << b)][b], dp[i][a] + mp[a][b]);
				int lst = tot - 1 - i;
				for (int j = lst; j; j = (j - 1) & lst) {
					int now = inc[j] + cot[j][a];
					dp[i | j][a] = max(dp[i | j][a], dp[i][a] + now);
				}
			}
		}
	}
	printf("%d\n", inc[tot - 1] - dp[tot - 1][n - 1]);
	return 0;
}
