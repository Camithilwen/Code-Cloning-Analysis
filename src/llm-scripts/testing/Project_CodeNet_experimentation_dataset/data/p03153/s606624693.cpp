#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;

using i64 = int64_t;

const i64 MOD = 1e9+7;

const i64 INF = 1e18+7;

struct UnionFind{
	int n;
	vector<int> par;
	UnionFind(int n) : n(n), par(n, -1){}
	int Find(int x){return par[x] < 0 ? x : Find(par[x]);}
	bool Unite(int x, int y){
		x = Find(x), y = Find(y);
		if(x == y)
			return false;
		if(par[x] > par[y])
			swap(x, y);
		par[x] += par[y];
		par[y] = x;
		return true;
	}
};

template<typename T>
struct Segtree{
	const int n;
	const T op;
	vector<T> elm;
	function<T(T, T)> f;

	Segtree(int n, T init, function<T(T, T)> f, T op = T()) :
			n(n),
			op(op),
			f(f),
			elm(2 * n, init)
	{
	}

	void set(int x, T val){
		x += n;
		elm[x] = val;
		while(x >>= 1)
			elm[x] = f(elm[2 * x], elm[2 * x + 1]);
	}

	void update(int x, T val){
		x += n;
		elm[x] = f(val, elm[x]);
		while(x >>= 1)
			elm[x] = f(elm[2 * x], elm[2 * x + 1]);
	}

	T get(int x, int y) const{
		T val = op;
		for(x += n, y += n - 1; x <= y; x >>= 1, y >>= 1){
			if(x & 1)
				val = f(val, elm[x++]);
			if(!(y & 1))
				val = f(val, elm[y--]);
		}
		return val;
	}
};


signed main(){

	int n, d;
	cin >> n >> d;
	vector<int> v(n);
	for(auto& x : v)
		cin >> x;


	auto f = [](pair<i64,int> x, pair<i64,int> y){
		return min(x, y);
	};

	Segtree<pair<i64,int>> seg_a(n, pair<i64,int>(), f, pair<i64,int>(INF, 0));
	Segtree<pair<i64,int>> seg_b(n, pair<i64,int>(), f, pair<i64,int>(INF, 0));

	auto s = [&](int i){
		seg_a.set(i, make_pair(v[i] + i64(1) * d * i, i));
		seg_b.set(i, make_pair(v[i] + i64(1) * d * (n - i - 1), i));
	};

	auto t = [&](int i){
		seg_a.set(i, make_pair(INF, i));
		seg_b.set(i, make_pair(INF, i));
	};

	for(int i = 0; i < n; ++i)
		s(i);

	UnionFind u(n);

	i64 ans = 0;

	while(u.par[u.Find(0)] != -n){
		// 子ノードの一覧
		vector<vector<int>> ch(n);
		// 接合するノード
		vector<pair<i64, int>> nex(n, make_pair(INF, 0));

		for(int i = 0; i < n; ++i)
			ch[u.Find(i)].push_back(i);

		for(int i = 0; i < n; ++i){
			if(ch[i].empty())
				continue;
			for(auto& x : ch[i])
				t(x);

			pair<i64,int> val(INF, 0);

			for(auto& x : ch[i]){
				auto p_a = seg_a.get(x + 1, n);
				p_a.first -= i64(1) * d * x;
				p_a.first += v[x];
				val = f(val, p_a);

				auto p_b = seg_b.get(0, x);
				p_b.first -= i64(1) * d * (n - 1 - x);
				p_b.first += v[x];
				val = f(val, p_b);
			}

			for(auto& x : ch[i])
				s(x);

			nex[i] = val;
		}

		for(int i = 0; i < n; ++i){
			if(nex[i].first != INF && u.Unite(i, nex[i].second))
				ans += nex[i].first;
		}
	}
	cout << ans << endl;
}
