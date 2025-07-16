#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn = 1007, maxm = 2007;
const int inf = 1e9 + 7;
int cnt = 1;
int head[maxn], vis[maxn], dfn[maxn], vis2[maxn];
//head[x]:点x连接的最后一条边号
//vis[x]:标记每次dfs访问过的点，以免重复搜索耗时
//dfn[x]:x的时间戳
//vis[x]2:dfs中标记访问过的次数，找环
int b[maxn];
struct edge
{
int u, v, next;
}e[maxm];
void addedge(int u, int v)//前向星
{
e[cnt].u = u;
e[cnt].v = v;
e[cnt].next = head[u];
head[u] = cnt;
cnt++;
}
vector<int> v;
int ans = inf;
void dfs(int x, int num)
{
vis[x] = 1;//标记x访问过
dfn[x] = num;
for (int i = head[x]; i ; i = e[i].next)//遍历x点连接的所有边
{
int y = e[i].v;
if (vis2[y] == 1)//y第二次被访问，说明形成环
{
if (dfn[x] - dfn[y] + 1 < ans)//ans记录最小环的大小
{
ans = dfn[x] - dfn[y] + 1;
int sz = v.size();
for (int i = 1; i <= ans; i++)
b[i] = v[sz - i];//b[i]存最小环的点
}
}
if (vis[y] == 0)//y没有访问过
{
vis2[y] = 1;
v.push_back(y);
dfs(y, num + 1);
}
}
v.pop_back();
vis2[x] = 0;
}
int main()
{
int n, m;
scanf("%d%d", &n, &m);
for (int i = 1; i <= m; i++)
{
int x, y;
scanf("%d%d", &x, &y);
addedge(x, y);
}
for (int i = 1; i <= n; i++)
{
if (vis[i] == 0)
{
v.clear();
v.push_back(i);
vis2[i] = 1;
dfs(i, 1);
}
}
if (ans == inf)
printf("-1\n");
else
{
printf("%d\n", ans);
for (int i = ans; i >= 1; i--)
printf("%d\n", b[i]);
}
return 0;
}