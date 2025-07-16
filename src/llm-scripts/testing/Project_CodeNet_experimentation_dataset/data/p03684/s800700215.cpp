#include<cstdio>
#include<algorithm>
using ll = long long;
struct edge{int u, v, cost;};
const static int MAX_N = 100000;
int par[MAX_N];
int rank[MAX_N];

void init_union_find(int n){
	for (int i = 0; i < n; ++i){
		par[i] = i;
		rank[i] = 0;
	}
}

int find(int x){
	if(par[x] == x) return x;
	else return par[x] = find(par[x]);
}

void unite(int x, int y){
	x = find(x);
	y = find(y);
	if(x == y) return;
	if(rank[x] < rank[y]){
		par[x] = y;
	}else{
		par[y] = x;
		if(rank[x] == rank[y]) rank[x]++;
	}
}

bool same(int x, int y){
	return find(x) == find(y);
}

bool comp(const edge& e1, const edge& e2){
	return e1.cost < e2.cost;
}

int main(){
	int N;
	scanf("%d", &N);
	std::pair<int, int> x[N], y[N];
	for (int i = 0; i < N; ++i){
		x[i].second = y[i].second = i;
		scanf("%d %d", &x[i].first, &y[i].first);
	}
	std::sort(x, x + N), std::sort(y, y + N);
	edge es[2*(N - 1)];
	for (int i = 0; i < N - 1; ++i){
		es[i].u = x[i].second;
		es[i].v = x[i + 1].second;
		es[i].cost = x[i + 1].first - x[i].first;
	}
	for (int i = N - 1; i < 2*(N - 1); ++i){
		es[i].u = y[i + 1 - N].second;
		es[i].v = y[i + 2 - N].second;
		es[i].cost = y[i + 2 - N].first - y[i + 1 - N].first;
	}
	std::sort(es, es + 2*(N - 1), comp);
	init_union_find(N);
	int total = 0;
	for (int i = 0; i < 2*(N - 1); ++i){
		edge e = es[i];
		if(!same(e.u, e.v)){
			unite(e.u, e.v);
			total += e.cost;
		}
	}
	printf("%d\n", total);
	return 0;
}