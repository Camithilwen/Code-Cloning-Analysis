#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;
const int MAXN = 100005;
const int MAXE = 200005;
const int NIL = -1;
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;

bool vis[MAXN];
struct Edge {
	int to, next, w;
	Edge() { next = -1; }
} edge[MAXE];

int N;
int prenum[MAXN], parent[MAXN], lowest[MAXN], head[MAXE], timer, cnt;

void dfs(int cur, int pre)
{
	prenum[cur] = lowest[cur] = timer++;
	vis[cur] = true;

	int next;

	for (int i = head[cur]; i != NIL; i = edge[i].next)
	{
		next = edge[i].to;
		if (!vis[next])
		{
			parent[next] = cur;
			dfs(next, cur);
			lowest[cur] = min(lowest[cur], lowest[next]);
		}
		else if (next != pre)
		{
			lowest[cur] = min(lowest[cur], prenum[next]);
		}
	}
}

void art_points()
{
	for (int i = 0; i < N; ++i)
		vis[i] = false;
	timer = 1;
	dfs(0, NIL);

	set<int> ans;
	int flag = 0;	//?????????

	for (int i = 1; i < N; ++i)
	{
		int p = parent[i];
		if (p == 0)
			++flag;
		else if (prenum[p] <= lowest[i])
			ans.insert(p);
	}

	if (flag > 1)
		ans.insert(0);

	for (set<int>::iterator it = ans.begin(); it != ans.end(); ++it)
		cout << *it << endl;

}

void add(int u, int v, int w)
{
	edge[cnt].to = v;
	edge[cnt].w = w;
	edge[cnt].next = head[u];
	head[u] = cnt++;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int m, s, t;
	cin >> N >> m;
	memset(head, NIL, sizeof(int) * 2 * (m + 1));
	cnt = 0;
	for (int i = 0; i < m; ++i)
	{
		cin >> s >> t;
		add(s, t, 0);
		add(t, s, 0);
	}
	art_points();
	return 0;
}