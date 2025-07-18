#include<bits/stdc++.h>
using namespace std;
const int MAXN = 305;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
template <typename T> void chkmax(T &x, T y) {x = max(x, y); }
template <typename T> void chkmin(T &x, T y) {x = min(x, y); } 
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
template <typename T> void write(T x) {
	if (x < 0) x = -x, putchar('-');
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
template <typename T> void writeln(T x) {
	write(x);
	puts("");
}
char s[MAXN];
int n, m, ans, dp[MAXN][MAXN][MAXN];
int main() {
	scanf("%s", s + 1);
	n = strlen(s + 1), read(m);
	for (int i = 1; i <= n; i++)
	for (int j = i; j <= n; j++)
	for (int k = 0; k <= n; k++)
		dp[i][j][k] = m + 1;
	dp[1][n][0] = 0;
	for (int i = 1; i <= n; i++)
	for (int j = n; j >= i; j--)
	for (int k = 0; k <= n; k++) {
		int tmp = dp[i][j][k];
		if (tmp == m + 1) continue;
		chkmin(dp[i + 1][j][k], tmp);
		chkmin(dp[i][j - 1][k], tmp);
		if (i == j) chkmax(ans, 2 * k + 1);
		else {
			int cost = s[i] != s[j];
			if (cost + tmp <= m) {
				chkmin(dp[i + 1][j - 1][k + 1], tmp + cost);
				chkmax(ans, 2 * k + 2);
			}
		}
	}
	writeln(ans);
	return 0;
}