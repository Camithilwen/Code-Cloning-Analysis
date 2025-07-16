#include <iostream>
#include <deque>
#include <utility>
#include <algorithm>
#include <map>
#include <vector>
#define llint long long
#define mod 998244353
#define inf 1e18

using namespace std;
typedef pair<llint, llint> P;
typedef pair<llint, P> E;

struct SegTree{
	int size;
	vector<P> seg;
	
	SegTree(){}
	SegTree(int size){
		this->size = size;
		seg.resize(1<<(size+1));
	}
	
	void init()
	{
		for(int i = 0; i < (1<<(size+1)); i++) seg[i] = P(inf, inf);
	}
	
	void update(int i, P val)
	{
		i += (1 << size);
		seg[i] = val;
		while(i > 1){
			i /= 2;
			seg[i] = min(seg[i*2], seg[i*2+1]);
		}
	}

	P query(int a, int b, int k, int l, int r)
	{
		if(b < l || r < a) return P(inf, inf);
		if(a <= l && r <= b) return seg[k];
		P lval = query(a, b, k*2, l, (l+r)/2);
		P rval = query(a, b, k*2+1, (l+r)/2+1, r);
		return min(lval, rval);
	}
	P query(int a, int b)
	{
		if(a > b) return P(inf, inf);
		return query(a, b, 1, 0, (1<<size)-1);
	}
};

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

llint n, d;
llint a[200005];
SegTree lseg(18), rseg(18);
vector<P> vec;
vector<E> evec;
UnionFind uf(200005);

int main(void)
{
	cin >> n >> d;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) vec.push_back(P(a[i], i));
	sort(vec.begin(), vec.end());
	
	lseg.init(), rseg.init();
	for(int i = 0; i < vec.size(); i++){
		int p = vec[i].second;
		P res = lseg.query(1, p-1);
		if(res.first < inf/2) evec.push_back(E(res.first+p*d+a[p], P(p, res.second)));
		res = rseg.query(p+1, n);
		if(res.first < inf/2) evec.push_back(E(res.first-p*d+a[p], P(p, res.second)));
		lseg.update(p, P(a[p]-p*d, p));
		rseg.update(p, P(a[p]+p*d, p));
	}
	sort(evec.begin(), evec.end());
	
	llint ans = 0;
	for(int i = 0; i < evec.size(); i++){
		llint u = evec[i].second.first, v = evec[i].second.second, w = evec[i].first;
		if(uf.same(u, v)) continue;
		ans += w;
		uf.unite(u, v);
	}
	cout << ans << endl;
	
	return 0;
}
