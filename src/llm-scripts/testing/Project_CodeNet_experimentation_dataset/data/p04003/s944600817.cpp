#include <bits/stdc++.h>
#define sc(x) scanf("%d", &x)
#define pr(x) printf("%d\n", x)
#define lowbit(x) (x & -x)
#define ll long long
#define N 500010
using namespace std;
ll tot = 0, head[N], v[N], dis[N], n, m, cnt;
struct Xiao
{
	int next, to, w;
}f[N * 3];
void add(int x, int y, int z)
{
	f[++tot].to = y;
	f[tot].next = head[x];
	f[tot].w = z;
	head[x] = tot;
}
void spfa()
{
	memset(dis, 127, sizeof dis);
	memset(v, 0, sizeof v);
	queue <int> q;
	q.push(1);
	v[1] = 1;
	dis[1] = 0;
	while (q.size())
	{
		int x = q.front();
		q.pop();
		for (int i = head[x]; i; i = f[i].next)
		{
			int y = f[i].to;
			if (dis[y] > dis[x] + f[i].w)
			{
				dis[y] = dis[x] + f[i].w;
				if (!v[y])
				{
					v[y] = 1;
					q.push(y);
				}
			}
		}
		v[x] = 0;
	}
}
map < pair <int, int>, int > p;
int get(int x, int y)
{
	if (p.find(make_pair(x, y)) != p.end()) return p[make_pair(x, y)];
	else return p[make_pair(x, y)] = ++cnt;
}
int main()
{
	//freopen("railway.in", "r", stdin);
	//freopen("railway.out", "w", stdout);
	sc(n);
	sc(m);
	cnt = n;
	for (int i = 1; i <= m; i++)
	{
		int x, y, z;
		sc(x);
		sc(y);
		sc(z);
		int p1 = get(x, z);
		int p2 = get(y, z);
		add(p2, p1, 0);
		add(p1, p2, 0);
		add(x, p1, 1);
		add(p1, x, 1);
		add(y, p2, 1);
		add(p2, y, 1);
	}
	spfa();
	printf("%lld\n", dis[n] > 2 * n ? -1 : dis[n] / 2);
	return 0;
}
