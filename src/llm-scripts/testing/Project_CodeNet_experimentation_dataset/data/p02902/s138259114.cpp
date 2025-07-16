/*
	bfs 找环
*/
#include <bits/stdc++.h>
#define N 1005
#define M 2005

using namespace std;

int n, m;
int dep[N];
int head[N], nex[M], to[M], e;
int stk[N], top;
bool instack[N], vis[N], G[N][N];
vector<int> res;

inline int Rd() {
	int x = 0; char ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return x;
}
inline void Ae(int u, int v) {
	nex[++e] = head[u], head[u] = e;
	to[e] = v;
}

void calc(int u, int v) {
	do {
		res.push_back(stk[top]);
	} while(stk[top--] != v);
	int ans = res.size();
	printf("%d\n", ans);
	for(int i = 0; i < ans; ++i) printf("%d\n", res[i]);
	exit(0);
}
void dfs(int u) {
	stk[++top] = u;
	instack[u] = vis[u] = true;
	for(int i = head[u]; i; i = nex[i]) {
		int v = to[i];
		if(vis[v]) {
			if(instack[v]) calc(u, v);
		} else {
			dfs(v);
		}
	}
	instack[u] = false, --top;
	return;
}

int main() {
	n = Rd(), m = Rd();
	for(int i = 1; i <= m; ++i) {
		int u = Rd(), v = Rd();
		G[u][v] = true;
		Ae(u, v);
	}
	
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			if(G[i][j] && G[j][i]) {
				puts("2");
				printf("%d\n%d\n", i, j);
				return 0;
			}	
		}
	}
	for(int i = 1; i <= n; ++i)
		if(!vis[i])
			dfs(i);
	puts("-1");
	return 0;	
}