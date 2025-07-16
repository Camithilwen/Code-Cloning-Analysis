#include <cstdio>
int N, a[100001], ref[100001], _[3][100001], d[100001], T[100001], cover[100001];
void P(int x)
{
	while (x <= N)
	{
		T[x]++;
		x += x & -x;
	}
}
int G(int x)
{
	int r = 0;
	while (x)
	{
		r += T[x];
		x &= x - 1;
	}
	return r;
}
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < 3; i++)
		for (int j = 1; j <= N; j++)
			scanf("%d", _[i] + j);
	for (int i = 1; i <= N; i++)
		if (_[0][i] == _[1][i] - 1 && _[1][i] == _[2][i] - 1 && _[2][i] % 3 == 0)
		{
			a[i] = _[2][i] / 3;
			ref[a[i]] = i;
			d[a[i]] = 0;
		}
		else if (_[0][i] == _[1][i] + 1 && _[1][i] == _[2][i] + 1 && _[0][i] % 3 == 0)
		{
			a[i] = _[0][i] / 3;
			ref[a[i]] = i;
			d[a[i]] = 1;
		}
		else
		{
			puts("No");
			return 0;
		}
	for (int i = 1; i <= N; i++)
		if (i - a[i] & 1)
		{
			puts("No");
			return 0;
		}
	for (int i = N - !(N & 1); i >= 1; i -= 2)
	{
		cover[i] ^= 1;
		cover[i + (G(ref[i]) << 1)] ^= 1;
		d[a[i]] ^= i - a[i] >> 1 & 1;
		P(ref[i]);
	}
	for (int i = 2; i <= N; i++)
		cover[i] ^= cover[i - 1];
	for (int i = 2; i <= N; i += 2)
		d[a[i]] ^= cover[i];
	for (int i = 1; i <= N; i += 2)
		a[i] = ref[i] = i;
	for (int i = 1; i <= N; i++)
		cover[i] = T[i] = 0;
	for (int i = N - (N & 1); i >= 2; i -= 2)
	{
		cover[i] ^= 1;
		cover[i + (G(ref[i]) << 1)] ^= 1;
		d[a[i]] ^= i - a[i] >> 1 & 1;
		P(ref[i]);
	}
	for (int i = 2; i <= N; i++)
		cover[i] ^= cover[i - 1];
	for (int i = 1; i <= N; i += 2)
		d[a[i]] ^= cover[i];
	if (N == 3)
		puts(d[1] == 0 && d[2] == 0 && d[3] == 0 ? "Yes" : "No");
	else if (N == 4)
		puts(d[1] == d[2] && d[2] == d[3] && d[3] == d[4] ? "Yes" : "No");
	else
	{
		int c0 = 0, c1 = 0;
		for (int i = 1; i <= N; i += 2)
			c0 += d[i];
		for (int i = 2; i <= N; i += 2)
			c1 += d[i];
		puts((c0 & 1) || (c1 & 1) ? "No" : "Yes");
		return 0;
	}
}
