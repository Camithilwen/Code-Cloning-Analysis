#include <bits/stdc++.h>
using namespace std::literals::string_literals;
using i64 = long long;
using std::cout;
using std::endl;
using std::cin;

template<typename T>
std::vector<T> make_v(size_t a){return std::vector<T>(a);}

template<typename T,typename... Ts>
auto make_v(size_t a,Ts... ts){
  return std::vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));
}

struct UnionFind{
	std::vector<int> data;
	
	UnionFind(int n){
		data.assign(n, -1);
	}
	
	bool unite(int x, int y){
		x = find(x); y = find(y);
		if(x == y) return false;
		if(data[x] > data[y]) std::swap(x, y);
		data[x] += data[y];
		data[y] = x;
		return true;
	}
	
	bool same(int x, int y){
		return find(x) == find(y);
	}
	
	int find(int k){
		if(data[k] < 0) return k;
		return data[k] = find(data[k]);
	}
	
	int size(int k){
		return -data[find(k)];
	}
};

int main() {
	int n; scanf("%d", &n);
	std::vector<std::pair<i64, int>> X, Y;
	for(int i = 0; i < n; i++) {
		int x, y; scanf("%d%d", &x, &y);

		X.push_back({x, i});
		Y.push_back({y, i});
	}
	sort(begin(X), end(X)); sort(begin(Y), end(Y));

	std::vector<std::pair<i64, std::pair<int, int>>> edges;
	for(int i = 0; i < n - 1; i++) {
		edges.push_back({X[i + 1].first - X[i].first, {X[i].second, X[i + 1].second}});
		edges.push_back({Y[i + 1].first - Y[i].first, {Y[i].second, Y[i + 1].second}});
	}
	sort(begin(edges), end(edges));

	i64 ans = 0;
	UnionFind uf(n);
	for(auto e: edges) {
		int x = e.second.first, y = e.second.second;
		if(uf.unite(x, y)) ans += e.first;
	}
	printf("%lld\n", ans);
	return 0;
}
