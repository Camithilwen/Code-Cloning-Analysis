#include <bits/stdc++.h>

const int MAXN = 100010;
int fa[MAXN], n, dep[MAXN], ans, K;
int head[MAXN], nxt[MAXN];
int dfs(int u) {
	int res = dep[u];
	for (int i = head[u]; i; i = nxt[i]) {
		dep[i] = dep[u] + 1;
		res = std::max(dfs(i), res);
	}
	if (res - dep[u] == K - 1 && fa[u] != 1) fa[u] = 1, ++ans, res = 0;
	return res;
}
void dfs2(int u) {
	for (int i = head[u]; i; i = nxt[i])
		dep[i] = dep[u] + 1, dfs2(i);
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> K;
	for (int i = 1; i <= n; ++i) std::cin >> fa[i];
	for (int i = 2; i <= n; ++i)
		nxt[i] = head[fa[i]], head[fa[i]] = i;
	for (int i = head[1]; i; i = nxt[i]) dfs(i);
	memset(head, 0, n + 1 << 2);
	memset(dep, 0, n + 1 << 2);
	for (int i = 2; i <= n; ++i)
		nxt[i] = head[fa[i]], head[fa[i]] = i;
	for (int i = head[1]; i; i = nxt[i]) dep[i] = 1, dfs2(i);
	bool flg = true;
	for (int i = 1; i <= n; ++i) flg &= (K - dep[i]) % (dep[fa[1]] + 1) == 0;
	ans += !flg;
	std::cout << ans << std::endl;
	return 0;
}
