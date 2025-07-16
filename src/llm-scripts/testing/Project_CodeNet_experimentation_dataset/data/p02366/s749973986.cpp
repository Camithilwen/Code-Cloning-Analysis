// Ref : https://book.mynavi.jp/ec/products/detail/id=35408
// Ref : http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=2679699#1

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int NV, NE;

struct artPoint {
	int cnt, N;
	vector<vector<int> > G;
	set<int> AP;
	vector<bool> visited;
	// DFS木の各頂点について, prenum: DFS木の訪問順番,
	// parent: 親の頂点番号, lowest: 親への辺以外から辿れる上位のprenum
	vector<int> prenum, parent, lowest;

	artPoint(int n):N(n),G(n),visited(n, false),prenum(n),parent(n),lowest(n){}
	
	void addVertex(int a, int b) {
		G[a].push_back(b);
		G[b].push_back(a);
	}

	void dfs(int cur, int prev) {
		prenum[cur] = lowest[cur] = cnt++;
		visited[cur] = true;
		int next;
		for (unsigned int i = 0; i < G[cur].size(); i++) {
			next = G[cur][i];
			if (!visited[next]) {
				parent[next] = cur;
				dfs(next, cur);
				// 深さ優先で探索するので、親は子がより上位に辿れれば更新
				lowest[cur] = min(lowest[cur], lowest[next]);
			}
			else if (next != prev) {
				// DFS木の訪問順番の上位が辿れれば更新
				lowest[cur] = min(lowest[cur], prenum[next]);
			}
		}
	}

	// ある点からの1回のDFSで、関節点を求める
	void build() {
		cnt = 1;
		dfs(0, -1); // 頂点番号0をルートとする深さ優先探索
		int np = 0;
		for (int i = 1; i < N; i++) { // ルート以外を処理する
			int p = parent[i];
			if (p == 0) np++;
			else if (prenum[p] <= lowest[i]) AP.insert(p);
		}
		if (np > 1) AP.insert(0); // ルートを処理する
	}

	void print() {
		for (set<int>::iterator it = AP.begin(); it != AP.end(); it++) {
			cout << *it << endl;
		}
	}
};

int main() {
	cin >> NV >> NE;
	artPoint A(NV);
	for (int i = 0; i < NE; i++) {
		int s, t;
		cin >> s >> t;
		A.addVertex(s, t);
	}

	A.build();
	A.print();

	return 0;
}
