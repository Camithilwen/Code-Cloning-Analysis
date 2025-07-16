#include <bits/stdc++.h>
using namespace std;

template<class T>
struct SegmentTree {
	using F = function<T(T, T)>;
	const T init;
	const F f;
	int sz;
	vector<T> seg;
	SegmentTree(int n, const T init, const F f) :
		init(init),
		f(f)
		{
			sz = 1;
			while(sz < n) sz <<= 1;
			seg.resize(sz << 1, init);
		}
	void update(int id) {
		while(id >>= 1) {
			seg[id] = f(seg[2 * id], seg[2 * id + 1]);
		}
	}
	void replace(int id, T x){
		id += sz;
		seg[id] = x;
		update(id);
	}
	// [l,r)
	T get(int l, int r){
		T L = init, R = init;
		for(l += sz, r += sz; l < r; l >>= 1, r>>= 1) {
			if(l & 1) L = f(L, seg[l++]);
			if(r & 1) R = f(seg[--r], R);
		}
		return f(L, R);
	}
	void debug(){
		int i = 1;
		for(int r = 2; r <= 2 * sz; r <<= 1) {
			while(i < r) {
				cout << seg[i++] << " ";
			}
			cout << "\n";
		}
	}
};

int main() {
	int n; cin >> n;
	pair<int, int> p[n];
	for(auto &e : p) {
		cin >> e.first >> e.second;
		e.second++;
	}
	sort(p, p + n);
	SegmentTree<int> segL(n, 0, [](int lhs, int rhs) {
		return max(lhs, rhs);
	});
	SegmentTree<int> segR(n, 1e9 + 10, [](int lhs, int rhs) {
		return min(lhs, rhs);
	});
	for(int i = 0; i < n; ++i) {
		segL.replace(i, p[i].first);
		segR.replace(i, p[i].second);
	}
	int ans = 0;
	for(int i = 0; i < n - 1; ++i) {
		{
			int l1 = p[i].first;
			int r1 = p[i].second;
			int l2 = max(segL.get(0, i), segL.get(i + 1, n));
			int r2 = min(segR.get(0, i), segR.get(i + 1, n));
			ans = max(ans, max(0, (r1 - l1)) + max(0, (r2 - l2)));
		}
		{
			int l1 = segL.get(0, i + 1);
			int r1 = segR.get(0, i + 1);
			int l2 = segL.get(i + 1, n);
			int r2 = segR.get(i + 1, n);
			ans = max(ans, max(0, (r1 - l1)) + max(0, (r2 - l2)));
		}
	}
	cout << ans << '\n';
	return 0;
}