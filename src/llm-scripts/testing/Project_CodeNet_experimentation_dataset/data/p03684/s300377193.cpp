#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define llint long long

using namespace std;
typedef pair<llint, llint> P;
typedef pair<llint, P> E;

struct UnionFind{
	int size;
	vector<int> parent;
	
	UnionFind(){}
	UnionFind(int size){
		this->size = size;
		parent.resize(size+1);
		init();
	}
	void init(){
		for(int i = 0; i <= size; i++) parent[i] = i;
	}
	int root(int i){
		if(parent[i] == i) return i;
		return parent[i] = root(parent[i]);
	}
	bool same(int i, int j){
		return root(i) == root(j);
	}
	void unite(int i, int j){
		int root_i = root(i), root_j = root(j);
		if(root_i == root_j) return;
		parent[root_i] = root_j;
	}
};

llint n;
P x[100005], y[100005];
vector<E> vec;
UnionFind uf(100005);

int main(void)
{
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> x[i].first >> y[i].first;
		x[i].second = y[i].second = i;
	}
	sort(x+1, x+n+1);
	sort(y+1, y+n+1);
	
	for(int i = 1; i < n; i++){
		vec.push_back(E(x[i+1].first-x[i].first, P(x[i].second, x[i+1].second)));
		vec.push_back(E(y[i+1].first-y[i].first, P(y[i].second, y[i+1].second)));
	}
	sort(vec.begin(), vec.end());
	
	llint ans = 0;
	for(int i = 0; i < vec.size(); i++){
		llint w = vec[i].first, u = vec[i].second.first, v = vec[i].second.second;
		if(uf.same(u, v)) continue;
		ans += w;
		uf.unite(u, v);
	}
	cout << ans << endl;
	
	return 0;
}