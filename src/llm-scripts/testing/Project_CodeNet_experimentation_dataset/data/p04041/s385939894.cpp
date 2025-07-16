#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
int n, a[3], cnt, ed;
int f[50][1 << 17], ans = 1;

inline int add(const int &x, const int &y) {
	return x + y < mod ? x + y : x + y - mod;
}
inline int sub(const int &x, const int &y) {
	return x - y < 0 ? x - y + mod : x - y;
}
inline int mul(const int &x, const int &y) { return (int)((ll)x * y % mod); }
int main() {
	scanf("%d%d%d%d", &n, &a[0], &a[1], &a[2]);
	for(int i = 1; i <= n; i++) ans = mul(ans, 10);
	cnt = (1 << a[0] + a[1] + a[2]) - 1;
	ed = (1 << a[0] - 1) | (1 << a[0] + a[1] - 1) | (1 << a[0] + a[1] + a[2] - 1);
	f[0][0] = 1;
	for(int i = 1; i <= n; i++)
		for(int j = 0; j <= cnt; j++)
			for(int k = 1; k <= 10; k++) {
				int t = (j << k) + (1 << k - 1); t &= cnt;
				if((t & ed) != ed) f[i][t] = add(f[i - 1][j], f[i][t]);
			}
	for(int i = 0; i <= cnt; i++) ans = sub(ans, f[n][i]);
	printf("%d\n", ans);
	return 0;
}