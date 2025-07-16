#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1400010;
inline int read()
{
	int a = 0, f = 1; char c = getchar();
	while(c > '9' || c < '0') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + c - '0'; c = getchar(); }
	return a * f;
}
int n, m;
int a[MAXN], pre[MAXN], Ans[MAXN];
struct node
{
	int l, r, id;
}ask[MAXN];
inline bool cmp(const node &a, const node &b)
{
	return a.r < b.r;
}
int c[MAXN];
inline int lowbit(int x)
{
	return x & (-x);
}
inline void add(int x, int dt)
{
	while(x <= 1000000)
	{
		c[x] += dt;
		x += lowbit(x);
	}
}
inline int sum(int x)
{
	int ans = 0;
	while(x)
	{
		ans += c[x];
		x -= lowbit(x);
	}
	return ans;
}
int main()
{
	n = read(); m = read();
	for (int i = 1; i <= n; i++) a[i] = read();
	for (int i = 1; i <= m; i++) ask[i].l = read(), ask[i].r = read(), ask[i].id = i;
	sort(ask + 1, ask + m + 1, cmp);	
	int nr = 0;
	for (int i = 1; i <= m; i++)
	{
		while(nr < ask[i].r)
		{
			nr++;
			if(pre[a[nr]]) add(pre[a[nr]], -1);
			pre[a[nr]] = nr;
			add(nr, 1);
		}
		Ans[ask[i].id] = sum(nr) - sum(ask[i].l - 1);
	}
	for (int i = 1; i <= m; i++)
		printf("%d\n", Ans[i]);
	return 0;
}