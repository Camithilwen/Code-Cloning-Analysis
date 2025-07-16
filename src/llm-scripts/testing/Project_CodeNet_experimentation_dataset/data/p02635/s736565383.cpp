#include <bits/stdc++.h>
#define debug(x) cerr << #x << " " << (x) << endl
using namespace std;

const int N = 305;
const long long mod = 998244353ll;

int n, K, num[N], pre[N], cnt = 0;
char str[N];
long long f[N][N << 1], g[N][N << 1], tmp[N][N << 1];

int main () {
	scanf("%s%d", str, &K), n = strlen(str);
	int pos = -1;
	for (int i = 0; str[i]; i++) {
		if (str[i] == '0') {
			num[++cnt] = i - pos - 1;
			pos = i;
		}
	}
	num[++cnt] = n - 1 - pos;
	pre[0] = 0;
	for (int i = 1; i <= cnt; i++) pre[i] = pre[i - 1] + num[i];

	for (int i = 0; i <= pre[cnt]; i++) {
		for (int j = 0; j <= (pre[cnt] << 1); j++) f[i][j] = 0ll;
	}
	f[0][0] = 1ll;
	for (int i = 1; i <= cnt; i++) {
		for (int j = 0; j <= (pre[cnt] << 1); j++) {
			tmp[0][j] = f[0][j];
			for (int k = 1; k <= pre[cnt]; k++) tmp[k][j] = (tmp[k - 1][j] + f[k][j]) % mod;
		}
		for (int j = 0; j <= pre[cnt]; j++) {
			for (int k = 0; k <= (pre[cnt] << 1); k++) {
				g[j][k] = 0ll;
				if (j >= pre[i]) {
					g[j][k] = j > num[i] ? tmp[j - num[i] - 1][k] : 0ll;
					for (int l = 0; l <= min(num[i], j); l++) {
						if (k + l >= num[i]) g[j][k] = (g[j][k] + f[j - l][k + l - num[i]]) % mod;
					}
				}
			}
		}
		for (int j = 0; j <= pre[cnt]; j++) {
			for (int k = 0; k <= (pre[cnt] << 1); k++) f[j][k] = g[j][k];
		}
	}

	long long ans = 0ll;
	for (int i = 0; i <= min(pre[cnt] << 1, K); i++) ans = (ans + f[pre[cnt]][i]) % mod;
	printf("%lld\n", ans);
	return 0;
}