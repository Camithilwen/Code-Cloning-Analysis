#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#define _USE_MATH_DEFINES
#include<math.h>
#include<queue>
#include<deque>
#include<stack>
#include<cstdio>
#include<utility>
#include<set>
#include<list>
#include<cmath>
#include<stdio.h>
#include<string.h>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
#define FOR(i, a, b) for (ll i = (a); i <= (b); i++)
#define REP(i, n) FOR(i, 0, n - 1)
#define NREP(i, n) FOR(i, 1, n)
using ll = long long;
using pii = pair<int, int>;
using piii = pair<pii, pii>;
const ll dx[4] = { 0,1,0,-1 };
const ll dy[4] = { -1, 0, 1,0 };
const ll INF = 1e9 + 7;
int gcd(int x, int y) {
	if (x < y)swap(x, y);
	if (y == 0)return x;
	return gcd(y, x%y);
}
void mul(ll a, ll b) {
	a = a * b % INF;
}
double mysqrt(double x) {
	double l = 0, r = x;
	for (int i = 0; i < 64; ++i) {
		double m = (l + r) / 2.0;
		if (m*m < x)l = m;
		else r = m;
	}
	return l;
}
///////////////////////////////////////

int V, E;
vector<int>G[10010];//グラフの隣接リスト表現
vector<int>rG[10010];//辺の向きを逆にしたグラフ
vector<int>vs;//帰りがけ順の並び
bool used[10010];//すでに調べたか
int cmp[10010];//属する強連結成分のトポロジカル順序
void add_edge(int from, int to) {
	G[from].push_back(to);
	rG[to].push_back(from);
}
void dfs(int v) {
	used[v] = true;
	for (int i = 0; i < G[v].size(); ++i) {
		if (!used[G[v][i]])dfs(G[v][i]);
	}
	vs.push_back(v);
}
void rdfs(int v, int k) {
	used[v] = true;
	cmp[v] = k;
	for (int i = 0; i < rG[v].size(); ++i) {
		if (!used[rG[v][i]])rdfs(rG[v][i], k);
	}
}
int main() {
	cin >> V >> E;
	REP(i, E) {
		int s, t;
		cin >> s >> t;
		G[s].push_back(t);
		rG[t].push_back(s);
	}
	int Q;
	cin >> Q;
	int num = 0;
	memset(used, 0, sizeof(used));
	vs.clear();
	for (int v = 0; v < V; ++v) {
		if (!used[v])dfs(v);
	}
	memset(used, 0, sizeof(used));
	for (int i = vs.size() - 1; i >= 0; i--) {
		if (!used[vs[i]])rdfs(vs[i], num++);
	}
	REP(i, Q) {
		int u, v;
		cin >> u >> v;
		if (cmp[u] == cmp[v]) {
			cout << 1 << endl;
		}
		else {
			cout << 0 << endl;
		}
	}
	return 0;
}

