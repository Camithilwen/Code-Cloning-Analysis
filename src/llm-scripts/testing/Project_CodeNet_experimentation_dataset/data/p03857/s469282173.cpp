#include <bits/stdc++.h>
#define DEBUG fprintf(stderr, "Passing [%s] line %d\n", __FUNCTION__, __LINE__)
#define File(x) freopen(x".in","r",stdin); freopen(x".out","w",stdout)

using namespace std;

typedef long long LL;
typedef pair <int, int> PII;
typedef pair <int, PII> PIII;

template <typename T>
inline T gi()
{
	T f = 1, x = 0; char c = getchar();
	while (c < '0' || c > '9') {if (c == '-') f = -1; c = getchar();}
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return f * x;
}

const int INF = 0x3f3f3f3f, N = 200003, M = N << 2;

int n, k, l;
int tot, head[N], headc[N], ver[M], nxt[M];
int in1[N], cnt1, in2[N], cnt2;
bool vis1[N], vis2[N];
map <PII, int> p;

inline void add(int h[], int u, int v)
{
	ver[++tot] = v, nxt[tot] = h[u], h[u] = tot;
}

void dfs1(int u, int id)
{
	in1[u] = id;
	vis1[u] = true;
	for (int i = head[u]; i; i = nxt[i])
	{
		int v = ver[i];
		if (!vis1[v]) dfs1(v, id);
	}
}

void dfs2(int u, int id)
{
	in2[u] = id;
	vis2[u] = true;
	for (int i = headc[u]; i; i = nxt[i])
	{
		int v = ver[i];
		if (!vis2[v]) dfs2(v, id);
	}
}

int main()
{
	//File("");
	n = gi <int> (), k = gi <int> (), l = gi <int> ();
	for (int i = 1; i <= k; i+=1)
	{
		int u = gi <int> (), v = gi <int> ();
		add(head, u, v), add(head, v, u);
	}
	for (int i = 1; i <= l; i+=1)
	{
		int u = gi <int> (), v = gi <int> ();
		add(headc, u, v), add(headc, v, u);
	}
	for (int i = 1; i <= n; i+=1)
		if (!vis1[i]) dfs1(i, ++cnt1);
	for (int i = 1; i <= n; i+=1)
		if (!vis2[i]) dfs2(i, ++cnt2);
	for (int i = 1; i <= n; i+=1) ++p[make_pair(in1[i], in2[i])];
	for (int i = 1; i <= n; i+=1)
		printf("%d ", p[make_pair(in1[i], in2[i])]);
	return 0;
}
