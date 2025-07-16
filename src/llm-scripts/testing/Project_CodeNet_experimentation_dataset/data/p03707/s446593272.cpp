#include <bits/stdc++.h>

template <class T>
inline void read(T &res)
{
	res = 0; bool bo = 0; char c;
	while (((c = getchar()) < '0' || c > '9') && c != '-');
	if (c == '-') bo = 1; else res = c - 48;
	while ((c = getchar()) >= '0' && c <= '9')
		res = (res << 3) + (res << 1) + (c - 48);
	if (bo) res = ~res + 1;
}

const int N = 2005;

int n, m, q, sum[N][N], sum1[N][N], sum2[N][N];
char s[N][N];

int main()
{
	int xl, yl, xr, yr;
	read(n); read(m); read(q);
	for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
			sum1[i][j] = sum1[i - 1][j] + sum1[i][j - 1] - sum1[i - 1][j - 1];
			sum2[i][j] = sum2[i - 1][j] + sum2[i][j - 1] - sum2[i - 1][j - 1];
			if (s[i][j] == '1')
			{
				sum[i][j]++; if (s[i - 1][j] == '1') sum1[i][j]++;
				if (s[i][j - 1] == '1') sum2[i][j]++;
			}
		}
	while (q--)
	{
		read(xl); read(yl); read(xr); read(yr);
		printf("%d\n", sum[xr][yr] - sum[xl - 1][yr] - sum[xr][yl - 1] +
			sum[xl - 1][yl - 1] - sum1[xr][yr] + sum1[xl][yr] + sum1[xr][yl - 1]
				- sum1[xl][yl - 1] - sum2[xr][yr] + sum2[xl - 1][yr]
					+ sum2[xr][yl] - sum2[xl - 1][yl]);
	}
	return 0;
}