#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
const int N = 2e6;

int n, m;
int tot = 0, tag = 0, cnt = 0;
int vis[N], b[N], fa[N], num[N], Link[N], dis[N]; 
struct node { int x, y; }; 
struct edge { int y, next, v; } e[N*2];
vector < node > a[N];

int read(void)
{
	int s = 0, w = 0; char c = getchar();
	while (c < '0' || c > '9') w |= c == '-', c = getchar();
	while (c >= '0' && c <= '9') s = s*10+c-48, c = getchar();
	return w ? -s : s;
}

int get(int x) {
	if (fa[x] == x) return x;
	return fa[x] = get(fa[x]);
}

void add(int x,int y,int v) {
	e[++tot] = edge{y,Link[x],v};
	Link[x] = tot;
}

void work(int x)
{
	int t = 0;
	tag ++;
	for (int i=0;i<a[x].size();++i)
	{
		int p1 = a[x][i].x, p2 = a[x][i].y;
		if (vis[p1] != tag) b[++t] = p1, vis[p1] = tag;
		if (vis[p2] != tag) b[++t] = p2, vis[p2] = tag;
	}
	for (int i=1;i<=t;++i) fa[b[i]] = b[i];
	for (int i=0;i<a[x].size();++i) 
	{
		int p1 = a[x][i].x, p2 = a[x][i].y;
		fa[get(p1)] = get(p2);
	}
	tag ++;
	for (int i=1;i<=t;++i)
	{
		int r = get(b[i]);
		if (vis[r] != tag) 
		{
			vis[r] = tag;
			num[r] = ++ cnt;
		}
		add(b[i],num[r],1);
		add(num[r],b[i],1);
	}
	return;
}

int Dijkstra(void)
{
	memset(vis,0,sizeof vis);
	memset(dis,30,sizeof dis);
	dis[1] = 0;
	priority_queue < pair<int,int> > q;
	q.push(make_pair(0,1));
	while (q.size())
	{
		int x = q.top().second; q.pop();
		if (vis[x]) continue; vis[x] = 1;
		if (x == n) return dis[x] / 2; 
		for (int i=Link[x];i;i=e[i].next)
		{
			int y = e[i].y, v = e[i].v;
			if (dis[x] + v < dis[y]) {
				dis[y] = dis[x] + v;
				q.push(make_pair(-dis[y],y));
			}
		}
	}
	return -1;
}

int main(void)
{
	n = cnt = read(), m = read();
	for (int i=1;i<=m;++i)
	{
		int x = read(), y = read(), v = read();
		a[v].push_back(node{x,y});
	}
	for (int i=1;i<=1e6;++i)
	    if (a[i].size()) work(i);
	printf("%d", Dijkstra());
	return 0;
} 