#include<bits/stdc++.h>
using namespace std;
int n, cnt = 2;
long long res[507][507];
map<int, int>a, b;
int nxt()
{
	while (1)
	{
		bool ok = 1;
		for (int i = 2; i * i <= cnt && ok; i++)
			if (cnt % i == 0)ok = 0;
		if (ok)return cnt++;
		cnt++;
	}
	return 0;
}
long long gcd(long long a, long long b)
{
	if (!b)return a;
	return gcd(b, a % b);
}
long long lcm(long long a, long long b)
{
	if (!a || !b)return 0;
	return a / gcd(a, b) * b;
}
int main()
{
	cin >> n;
	if (n == 2) {
		printf("4 7\n23 10\n");
		return 0;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			res[i][j] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (((i + j) & 1) && !a[i + j])
				a[i + j] = nxt();
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (((i + j) & 1) && !b[i - j])
				b[i - j] = nxt();
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if ((i + j) & 1)
			{
				res[i][j] = 1LL * a[i + j] * b[i - j];
				res[i - 1][j] = lcm(res[i - 1][j], res[i][j]);
				res[i][j - 1] = lcm(res[i][j - 1], res[i][j]);
				res[i + 1][j] = lcm(res[i + 1][j], res[i][j]);
				res[i][j + 1] = lcm(res[i][j + 1], res[i][j]);
			}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (!((i + j) & 1))
				res[i][j]++;
	for (int i = 1; i <= n; i++, putchar('\n'))
		for (int j = 1; j <= n; j++)
			printf("%lld ", res[i][j]);
	return 0;
}