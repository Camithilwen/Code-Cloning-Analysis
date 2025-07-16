#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 1000010;
int n;
int a[N];
int L, q, ans, lst;
int dp[N][21];
int pow[21];
int main() {
	memset(dp, 0x3f, sizeof(dp));
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	scanf("%d", &L);
	scanf("%d", &q);
	pow[0] = 1;
	lst = 1;
	for (int i = 1; i <= n; i++) {
		while (a[i] > a[lst] + L) {
			dp[lst++][0] = i - 1;
		}
	}
	for (int j = 1; j <= 20; j++) {
		pow[j] = pow[j - 1] << 1; 
		for (int i = 1; i <= n; i++) {
			if (dp[i][j - 1] < 0x3f3f3f3f) dp[i][j] = dp[dp[i][j - 1]][j - 1];
		}
	}
	while (q--) {
		int x, y;
		scanf("%d%d", &x, &y);
		if (x > y) swap(x, y);
		ans = 0;
		for (int i = 20; i >= 0; i--) {
			if (dp[x][i] < y) {
				x = dp[x][i];
				ans += pow[i];
			}
		}
		printf("%d\n", ans + 1);
	}
	return 0;
}