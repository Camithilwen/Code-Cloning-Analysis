#include<iostream>
#include<string>
#include<algorithm>    
#include<cmath>
#include<map>
#include<vector>
#include<math.h>
#include<stdio.h>
#include<stack>
#include<queue>
#include<tuple>
#include<cassert>
#include<set>
#define int long long
#define mod(int)(1000000007)
using namespace std;
int par[213456];//親
int depth[213456];//木の深さ
//n要素で初期化
void init(int n) {
	for (int i = 0; i <= n; i++) {
		par[i] = i;
		depth[i] = 0;
	}
}
//木の根を求める
int find(int x) {
	if (par[x] == x) {
		return x;
	}
	else {
		return par[x] = find(par[x]);
	}
}
//xとyの属する集合を併合
void unite(int x, int y) {
	x = find(x); y = find(y);
	if (x == y) { return; }
	if (depth[x] < depth[y]) {
		par[x] = y;
	}
	else {
		par[y] = x;
		if (depth[x] == depth[y])depth[x]++;
	}
}
//xとyが同じ集合に属するか否か
bool same(int x, int y) {
	return find(x) == find(y);
}
struct edge { int u, v, cost; };
bool comp(const edge& e1, const edge& e2) {
	return e1.cost < e2.cost;
}
edge es[345678];
int kruskal(int V, int E) { //頂点数と辺数
	sort(es, es + E, comp); //edge.costが小さい順にソート
	init(V); //Union-Findの初期化
	int res = 0;
	for (int i = 0; i < E; i++) {
		edge e = es[i];
		if (!same(e.u, e.v)) {
			unite(e.u, e.v);
			res += e.cost;
		}
	}
	return res;
}
signed main() {
	int n; cin >> n;
	vector<vector<int>>aa(n, vector<int>(3));
	vector<vector<int>>bb(n, vector<int>(3));
	for (int h = 0; h < n; h++) {
		cin >> aa[h][0] >> aa[h][1]; aa[h][2] = h;
		bb[h][0] = aa[h][1]; bb[h][1] = aa[h][0]; bb[h][2] = h;
	}
	sort(aa.begin(), aa.end());
	int x = 0;
	for (int h = 1; h < n; h++) {
		es[x] = { aa[h - 1][2], aa[h][2], min(abs(aa[h - 1][0] - aa[h][0]),abs(aa[h - 1][1] - aa[h][1])) };
		x++;
	}
	sort(bb.begin(), bb.end());
	for (int h = 1; h < n; h++) {
		es[x] = { bb[h - 1][2], bb[h][2], min(abs(bb[h - 1][0] - bb[h][0]),abs(bb[h - 1][1] - bb[h][1])) };
		x++;
	}
	cout << kruskal(n, x) << endl;
	return 0;
}