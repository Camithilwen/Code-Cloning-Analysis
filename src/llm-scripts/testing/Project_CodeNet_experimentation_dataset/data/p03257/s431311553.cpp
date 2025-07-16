#include <cstdio>
using ll = long long;
inline ll gcd(ll x, ll y)
{
	while (y)
	{
		auto r = x % y;
		x = y;
		y = r;
	}
	return x;
}
inline bool chk(int n)
{
	for (int i = 2; i * i <= n; i++)
	{
		if (!(n % i))
			return false;
	}
	return true;
}
inline ll lcm(ll x, ll y) { return x && y ? x / gcd(x, y) * y : x + y; }
ll pri[1005], arr[505][505];
int main()
{
	// freopen("AGC027-D.in", "r", stdin);
	int n, cur = 0, len = 0;
	scanf("%d", &n);
	bool even = n & 1 ^ 1;
	n += even;
	for (int i = 2; len <= n * 2; i++)
	{
		if (chk(i))
			pri[len++] = i;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			arr[i][j] = 1;
	}
	for (int i = 0; i < n; i += 2, cur++)
	{
		int x = i, y = 0;
		while (x < n && y < n)
			arr[x++][y++] *= pri[cur];
	}
	for (int i = 2; i < n; i += 2, cur++)
	{
		int x = 0, y = i;
		while (x < n && y < n)
			arr[x++][y++] *= pri[cur];
	}
	cur = len - 1;
	for (int i = 0; i < n; i += 2, cur--)
	{
		int x = i, y = 0;
		while (x >= 0 && y < n)
			arr[x--][y++] *= pri[cur];
	}
	for (int i = 2; i < n; i += 2, cur--)
	{
		int x = n - 1, y = i;
		while (x >= 0 && y < n)
			arr[x--][y++] *= pri[cur];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i & 1 ^ 1; j < n; j += 2)
			arr[i][j] = lcm(lcm(i ? arr[i - 1][j] : 0, j ? arr[i][j - 1] : 0),
							lcm(arr[i + 1][j], arr[i][j + 1])) + 1;
	}
	n -= even;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			printf("%lld%c", arr[i][j], " \n"[j + 1 == n]);
	}
	return 0;
}
