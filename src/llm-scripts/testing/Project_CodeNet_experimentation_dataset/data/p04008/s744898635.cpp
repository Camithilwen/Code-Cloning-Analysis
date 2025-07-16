#include <bits/stdc++.h>

using namespace std;

#define N 100000
#define pb push_back

int n, k, len, a[N + 5], d[N + 5], vis[N + 5], ans;
vector<int> G[N + 5];

struct Cmp {
	bool operator () (const int &a, const int &b) const {
		return d[a] < d[b];
	}
};
priority_queue<int, vector<int>, Cmp> pq;

void dfs1(int u) {
	for (int i = 0, v; i < G[u].size(); ++i) {
		v = G[u][i];
		d[v] = d[u] + 1;
		dfs1(v);
	}
}

void dfs2(int u) {
	len++;
	if (u == 1)
		return ;
	dfs2(a[u]);
}

void mark(int u) {
	vis[u] = 1;
	for (int i = 0, v; i < G[u].size(); ++i) {
		v = G[u][i];
		if (vis[v])
			continue;
		mark(v);
	}
}

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	dfs2(a[1]);
	for (int i = 2; i <= n; ++i)
		G[a[i]].pb(i);
	dfs1(1);
	bool flag = 1;
	for (int i = 1; i <= n; ++i)
		if (d[i] > k || (k - d[i]) % len) {
			flag = 0;
			break;
		}
	if (flag)
		ans = 0;
	else {
		if (a[1] != 1) ans = 1;
		else ans = 0;
		a[1] = 1;
		for (int i = 2; i <= n; ++i)
			pq.push(i);
		while (!pq.empty()) {
			int u = pq.top(), v; pq.pop();
			if (d[u] <= k || vis[u])
				continue;
			ans++;
			v = u;
			for (int i = 1; i <= k - 1; ++i)
				v = a[v];
			a[v] = 1;
//			printf("u:%d v:%d\n", u, v);
			mark(v);
		}
	}
	printf("%d\n", ans);
//	for (int i = 1; i <= n; ++i) printf("%d ", a[i]);
//	printf("\n");
	return 0;
}