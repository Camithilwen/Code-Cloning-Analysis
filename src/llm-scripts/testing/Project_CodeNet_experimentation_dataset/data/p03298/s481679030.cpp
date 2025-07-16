#include<bits/stdc++.h>
using namespace std;
const int MAXN = 40;
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
char s[MAXN], a[MAXN], b[MAXN];
int n, dp[MAXN][MAXN]; ll ans;
void work(int pos, int la, int lb) {
	if (pos == n) {
		memset(dp, 0, sizeof(dp)), dp[n][la] = 1;
		for (int i = n; i >= 1; i--)
		for (int j = max(0, i - lb), k = i - j; j <= la && j <= i; j++, k--) {
			if (s[i] == a[j]) dp[i - 1][j - 1] += dp[i][j];
			if (s[i] == b[k]) dp[i - 1][j] += dp[i][j];
		}
		ans += dp[0][0];
		return;
	}
	a[la + 1] = s[pos];
	work(pos - 1, la + 1, lb);
	b[lb + 1] = s[pos];
	work(pos - 1, la, lb + 1);
}
int main() {
	read(n), scanf("%s", s + 1);
	work(n * 2, 0, 0);
	writeln(ans);
	return 0;
}