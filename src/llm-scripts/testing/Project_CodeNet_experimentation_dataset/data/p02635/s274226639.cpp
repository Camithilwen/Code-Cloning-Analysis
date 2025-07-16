//%std
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read()
{
	int out = 0, fh = 1;
	char jp = getchar();
	while ((jp > '9' || jp < '0') && jp != '-')
		jp = getchar();
	if (jp == '-')
		fh = -1, jp = getchar();
	while (jp >= '0' && jp <= '9')
		out = out * 10 + jp - '0', jp = getchar();
	return out * fh;
}
void print(int x)
{
	if (x >= 10)
		print(x / 10);
	putchar('0' + x % 10);
}
void write(int x, char c)
{
	if (x < 0)
		putchar('-'), x = -x;
	print(x);
	putchar(c);
}
const int P = 998244353;
int add(int a, int b)
{
	return a + b >= P ? a + b - P : a + b;
}
void inc(int &a, int b)
{
	a = add(a, b);
}
int mul(int a, int b)
{
	return 1LL * a * b % P;
}
const int N = 300 + 10;
int n, m = 0, K, a[N], dp[N][N][N];
char buf[N];
int main()
{
	scanf("%s", buf + 1), n = strlen(buf + 1), K = min(n, read());
	int cnt = 0;
	for (int i = 1; i <= n; ++i)
		if (buf[i] == '0')
			a[++m] = cnt, cnt = 0;
		else
			++cnt;
	if (cnt)
		a[++m] = cnt;
	dp[m + 1][0][0] = 1;
	for (int i = m; i >= 1; --i)
	{
		for (int j = 0; j <= n; ++j)
			for (int k = n; k >= 0; --k)
				dp[i][j][k] = add(dp[i][j][k + 1], dp[i + 1][j][k]);
		for (int p = 1; p <= a[i]; ++p)
			for (int j = 0; j + p <= n; ++j)
				for (int k = 0; k + p <= n; ++k)
					inc(dp[i][j + p][k + p], dp[i + 1][j][k]);
	}
	int ans = 0;
	for (int j = 0; j <= K; ++j)
		inc(ans, dp[1][j][0]);
	write(ans, '\n');
	return 0;
}
