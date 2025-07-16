#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, q, a, b, l, val[800007][3], tag[800007];
int read()
{
	int num = 0;
	char c = getchar();
	while (c<'0' || c>'9')c = getchar();
	while (c >= '0' && c <= '9')num = num * 10 + c - '0', c = getchar();
	return num;
}
int add(int w, int v)
{
	for (int j = 0; j <= 2; j++)
		val[w][j] += v;
	tag[w] += v;
	return 0;
}
int down(int w)
{
	if (!tag[w])return 0;
	add(2 * w, tag[w]);
	add(2 * w + 1, tag[w]);
	tag[w] = 0;
	return 0;
}
int up(int w)
{
	for (int i = 0; i <= 2; i++)
		val[w][i] = min(val[2 * w][i], val[2 * w + 1][i]);
	return 0;
}
int change(int w, int l, int r, int x, int v)
{
	if (l == r)
	{
		val[w][0] = v;
		val[w][1] = v - x;
		val[w][2] = v + x;
		return 0;
	}
	down(w);
	int mid = (l + r) / 2;
	if (x <= mid)change(2 * w, l, mid, x, v);
	else change(2 * w + 1, mid + 1, r, x, v);
	up(w);
	return 0;
}
int ask(int p, int w, int l, int r, int x, int y)
{
	if (x <= l && r <= y)
		return val[w][p];
	down(w);
	int mid = (l + r) / 2, res = 1e18;
	if (x <= mid)res = min(res, ask(p, 2 * w, l, mid, x, y));
	if (y > mid)res = min(res, ask(p, 2 * w + 1, mid + 1, r, x, y));
	return res;
}
signed main()
{
	n = read();
	q = read();
	a = read();
	b = read();
	l = read();
	memset(val, 0x3f, sizeof val);
	change(1, 1, n, b, abs(l - a));
	change(1, 1, n, a, abs(l - b));
	for (int i = 2; i <= q; i++)
	{
		int num = read(), len = abs(num - l);
		int res1 = ask(0, 1, 1, n, num, num) + len;
		int res2 = ask(1, 1, 1, n, 1, num) + num;
		int res3 = ask(2, 1, 1, n, num + 1, n) - num;
		add(1, len);
		change(1, 1, n, l, min(res1, min(res2, res3)));
		l = num;
	}
	printf("%lld\n", val[1][0]);
	return 0;
}