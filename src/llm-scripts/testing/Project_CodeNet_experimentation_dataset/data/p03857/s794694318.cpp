#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
const double PI = 3.141592653589793238;
const double EPS = 1e-10;
struct UnionFind {
	vector<int> par;
	vector<int> rank;
	vector<int> cmp;
	int size;
	UnionFind(int n) :size(n) {
		par.resize(size);
		rank.resize(size);
		cmp.resize(size);
		for (int i = 0; i < size; i++) {
			par[i] = i;
			rank[i] = 0;
			cmp[i] = 1;
		}
	}
	void unite(int x, int y) {
		x = find(x);
		y = find(y);
		if (x == y) return;
		if (rank[x] < rank[y]) {
			par[x] = y;
			cmp[y] += cmp[x];
		}
		else {
			par[y] = x;
			cmp[x] += cmp[y];
			if (rank[x] == rank[y]) rank[x]++;
		}
	}
	int find(int x) {
		if (par[x] == x) return x;
		return par[x] = find(par[x]);
	}
	bool same(int x, int y) {
		x = find(x);
		y = find(y);
		return x == y;
	}
};
map<int, int> cnt[200000];
int main() {
	int N, K, L;
	cin >> N >> K >> L;
	UnionFind u1(N), u2(N);
	for (int i = 0; i < K; i++) {
		int p, q;
		cin >> p >> q;
		p--; q--;
		u1.unite(p, q);
	}
	for (int i = 0; i < L; i++) {
		int r, s;
		cin >> r >> s;
		r--; s--;
		u2.unite(r, s);
	}
	for (int i = 0; i < N; i++) {
		int x = u1.find(i);
		int y = u2.find(i);
		cnt[x][y]++;
	}

	for (int i = 0; i < N; i++) {
		int x = u1.find(i);
		int y = u2.find(i);
		cout << cnt[x][y] << " ";
	}
	cout << endl;
 }
