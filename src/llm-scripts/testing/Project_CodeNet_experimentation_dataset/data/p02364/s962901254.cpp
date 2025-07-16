#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
#define MAX_V 10000
#define MAX_E 10000

int par[MAX_V];
int rank_[MAX_V];

void init(int V) {
	for (int i = 0; i < V; i++) {
		par[i] = i;
		rank_[i] = 0;
	}
}

int root(int x) {
	if (par[x] == x) {
		return x;
	}
	return par[x] = root(par[x]);
}

void unite(int x, int y) {
	x = root(x);
	y = root(y);
	if (x == y) {
		return;
	}
	if (rank_[x] < rank_[y]) {
		par[x] = y;
	}
	else if (rank_[x]==rank_[y]){
		par[y] = x;
		rank_[x]++;

	}
	else if (rank_[y] < rank_[x]) {
		par[y] = x;
	}
}

bool same(int x, int y) {
	return root(x) == root(y);
}

struct edge {
	int from, to, cost;
	bool operator<(const edge& other)const {
		return cost < other.cost;
	}
};

using edges = vector<edge>;


int kruskal(edges&  es,int V) {
	
	
	sort(es.begin(), es.end());
	int E = es.size();
	init(V);
	int res = 0;
	for (int i = 0; i < E; i++) {
		if (!same(es[i].from, es[i].to)) {
			unite(es[i].from, es[i].to);
			res += es[i].cost;
		}
	}
	return res;
}

int main() {
	int V, E;
	cin >> V >> E;
	edges es(E);
	for(int i=0;i<E;i++){
		cin >> es[i].from >> es[i].to >> es[i].cost;
	    
	}
	cout << kruskal(es, V) << endl;
	return 0;
}





